"use client";

import React, { useState, useEffect, useRef, useCallback } from 'react';
import { Play, Pause, RefreshCw, AlertOctagon, Terminal, Users, List, AlignCenter, ArrowRightLeft } from 'lucide-react';

const STATES = {
  THINKING: { id: 'THINKING', label: 'Thinking', color: 'bg-slate-200 border-slate-400', text: 'text-slate-600' },
  HUNGRY: { id: 'HUNGRY', label: 'Hungry (Waiting)', color: 'bg-amber-300 border-amber-500 shadow-amber-400/50', text: 'text-amber-800' },
  EATING: { id: 'EATING', label: 'Eating', color: 'bg-emerald-400 border-emerald-600 shadow-emerald-400/50', text: 'text-emerald-900' }
};

const MODES = {
  UNRESTRICTED: { id: 'UNRESTRICTED', name: 'Unrestricted (Can Deadlock)', desc: 'Standard rules. Pick up left, then right. Very prone to deadlocks if everyone is hungry simultaneously.', icon: <Users size={16}/> },
  N_MINUS_1: { id: 'N_MINUS_1', name: 'N-1 Rule', desc: 'Maximum of 4 philosophers are allowed to be hungry at the same time.', icon: <List size={16}/> },
  BOTH_OR_NONE: { id: 'BOTH_OR_NONE', name: 'Both or None (Atomic)', desc: 'Philosophers only pick up chopsticks if BOTH left and right are available.', icon: <AlignCenter size={16}/> },
  EVEN_ODD: { id: 'EVEN_ODD', name: 'Even / Odd Asymmetry', desc: 'Even seats pick left then right. Odd seats pick right then left. Breaks circular wait.', icon: <ArrowRightLeft size={16}/> }
};

const NUM_PHILOSOPHERS = 5;

// Default initial state
const getInitialState = () => ({
  tick: 0,
  philosophers: Array(NUM_PHILOSOPHERS).fill().map((_, i) => ({
    id: i,
    state: STATES.THINKING.id,
    timeLeft: Math.floor(Math.random() * 3) + 2, // random initial thinking time
    holding: [] // array of chopstick IDs
  })),
  chopsticks: Array(NUM_PHILOSOPHERS).fill(null), // null = on table, number = philosopher ID
  logs: ['[System] Table initialized. Philosophers are seated.'],
  isDeadlocked: false,
});

export default function DiningPhilosophers() {
  const [gameState, setGameState] = useState(getInitialState());
  const [isRunning, setIsRunning] = useState(false);
  const [mode, setMode] = useState(MODES.UNRESTRICTED.id);
  const [speed, setSpeed] = useState(1000); // ms per tick

  // Geometric calculations for positioning
  const getCoordinates = (index, total, radius, offsetAngle = 0) => {
    const angle = (index / total) * 2 * Math.PI - (Math.PI / 2) + offsetAngle;
    return {
      left: `calc(50% + ${Math.cos(angle) * radius}%)`,
      top: `calc(50% + ${Math.sin(angle) * radius}%)`,
    };
  };

  const runSimulationTick = useCallback(() => {
    setGameState(prev => {
      if (prev.isDeadlocked) return prev;

      let nextPhil = JSON.parse(JSON.stringify(prev.philosophers));
      let nextChop = [...prev.chopsticks];
      let newLogs = [...prev.logs];
      const log = (msg) => {
        newLogs.unshift(`[Tick ${prev.tick + 1}] ${msg}`);
        if (newLogs.length > 50) newLogs.length = 50;
      };

      let activeCount = nextPhil.filter(p => p.state !== STATES.THINKING.id).length;

      // Process each philosopher
      for (let i = 0; i < NUM_PHILOSOPHERS; i++) {
        let p = nextPhil[i];
        let left = i;
        let right = (i + 1) % NUM_PHILOSOPHERS;

        // 1. If Eating
        if (p.state === STATES.EATING.id) {
          p.timeLeft--;
          if (p.timeLeft <= 0) {
            // Finish eating, release chopsticks
            p.holding.forEach(c => { nextChop[c] = null; });
            p.holding = [];
            p.state = STATES.THINKING.id;
            p.timeLeft = Math.floor(Math.random() * 4) + 2; // Think for 2-5 ticks
            log(`P${i} finished eating and started thinking.`);
            activeCount--;
          }
          continue;
        }

        // 2. If Thinking
        if (p.state === STATES.THINKING.id) {
          p.timeLeft--;
          if (p.timeLeft <= 0) {
            // Try to get hungry
            if (mode === MODES.N_MINUS_1.id && activeCount >= NUM_PHILOSOPHERS - 1) {
              // Denied entry to the room
              continue; 
            }
            p.state = STATES.HUNGRY.id;
            log(`P${i} became hungry.`);
            activeCount++;
          }
          continue;
        }

        // 3. If Hungry (Algorithm execution)
        if (p.state === STATES.HUNGRY.id) {
          
          if (mode === MODES.UNRESTRICTED.id || mode === MODES.N_MINUS_1.id) {
            // Standard Left-then-Right pickup
            if (p.holding.length === 0) {
              if (nextChop[left] === null) {
                nextChop[left] = i;
                p.holding.push(left);
                log(`P${i} grabbed left chopstick 🥢${left}`);
              }
            } else if (p.holding.length === 1 && p.holding[0] === left) {
              if (nextChop[right] === null) {
                nextChop[right] = i;
                p.holding.push(right);
                p.state = STATES.EATING.id;
                p.timeLeft = 3; // Eat for 3 ticks
                log(`P${i} grabbed right chopstick 🥢${right} and is EATING.`);
              }
            }
          } 
          
          else if (mode === MODES.BOTH_OR_NONE.id) {
            if (p.holding.length === 0) {
              if (nextChop[left] === null && nextChop[right] === null) {
                nextChop[left] = i;
                nextChop[right] = i;
                p.holding.push(left, right);
                p.state = STATES.EATING.id;
                p.timeLeft = 3;
                log(`P${i} atomically grabbed both 🥢${left} & 🥢${right} and is EATING.`);
              }
            }
          }
          
          else if (mode === MODES.EVEN_ODD.id) {
            const isEven = i % 2 === 0;
            const firstTarget = isEven ? left : right;
            const secondTarget = isEven ? right : left;

            if (p.holding.length === 0) {
              if (nextChop[firstTarget] === null) {
                nextChop[firstTarget] = i;
                p.holding.push(firstTarget);
                log(`P${i} (${isEven ? 'Even' : 'Odd'}) grabbed primary chopstick 🥢${firstTarget}`);
              }
            } else if (p.holding.length === 1 && p.holding[0] === firstTarget) {
              if (nextChop[secondTarget] === null) {
                nextChop[secondTarget] = i;
                p.holding.push(secondTarget);
                p.state = STATES.EATING.id;
                p.timeLeft = 3;
                log(`P${i} grabbed secondary chopstick 🥢${secondTarget} and is EATING.`);
              }
            }
          }
        }
      }

      // 4. Deadlock Detection
      // Deadlock happens if ALL philosophers are HUNGRY and ALL are holding exactly 1 chopstick
      const isDeadlockedNow = nextPhil.every(p => p.state === STATES.HUNGRY.id && p.holding.length === 1);
      if (isDeadlockedNow) {
        log(`🛑 DEADLOCK DETECTED! Everyone is stuck waiting.`);
      }

      return {
        tick: prev.tick + 1,
        philosophers: nextPhil,
        chopsticks: nextChop,
        logs: newLogs,
        isDeadlocked: isDeadlockedNow
      };
    });
  }, [mode]);

  useEffect(() => {
    let interval = null;
    if (isRunning && !gameState.isDeadlocked) {
      interval = setInterval(() => {
        runSimulationTick();
      }, speed);
    } else if (gameState.isDeadlocked) {
      setIsRunning(false);
    }
    return () => clearInterval(interval);
  }, [isRunning, runSimulationTick, speed, gameState.isDeadlocked]);

  const triggerDeadlock = () => {
    setMode(MODES.UNRESTRICTED.id);
    setIsRunning(false);
    
    // Force a deadlock scenario manually
    setGameState(prev => ({
      tick: prev.tick + 1,
      philosophers: prev.philosophers.map((p, i) => ({
        id: i,
        state: STATES.HUNGRY.id,
        timeLeft: 0,
        holding: [i] // Everyone holding their left chopstick
      })),
      chopsticks: prev.chopsticks.map((_, i) => i), // chopstick i owned by philosopher i
      logs: [`[System] 🛑 MANUAL DEADLOCK TRIGGERED! All grabbed their left chopstick.`, ...prev.logs],
      isDeadlocked: true
    }));
  };

  const resetState = () => {
    setGameState(getInitialState());
    setIsRunning(false);
  };

  return (
    <div className="min-h-screen bg-slate-50 p-4 md:p-8 font-sans text-slate-800 flex flex-col items-center">
      
      {/* Header */}
      <div className="w-full max-w-6xl mb-6">
        <h1 className="text-3xl md:text-4xl font-bold text-slate-900 mb-2">Dining Philosophers Visualizer</h1>
        <p className="text-slate-600 font-medium max-w-3xl">
          Watch semaphores and concurrency in action. Five philosophers alternate between thinking and eating spaghetti, but they need *two* chopsticks to eat. See how different algorithms prevent deadlocks!
        </p>
      </div>

      <div className="w-full max-w-6xl grid grid-cols-1 xl:grid-cols-12 gap-8">
        
        {/* Left Column: Controls & Logs */}
        <div className="xl:col-span-5 space-y-6 flex flex-col h-[700px]">
          
          {/* Controls Panel */}
          <div className="bg-white p-6 rounded-2xl shadow-sm border border-slate-200">
            <h2 className="text-lg font-bold mb-4 border-b pb-2">Algorithm & Controls</h2>
            
            <div className="mb-6 space-y-2">
              {Object.values(MODES).map(m => (
                <label 
                  key={m.id} 
                  className={`flex flex-col p-3 rounded-lg border-2 cursor-pointer transition-all ${mode === m.id ? 'border-indigo-500 bg-indigo-50/50' : 'border-slate-100 hover:border-indigo-200 bg-white'}`}
                >
                  <div className="flex items-center gap-2 mb-1">
                    <input 
                      type="radio" 
                      name="mode" 
                      value={m.id} 
                      checked={mode === m.id} 
                      onChange={() => { setMode(m.id); resetState(); }}
                      className="text-indigo-600 focus:ring-indigo-500"
                    />
                    <span className={`font-semibold flex items-center gap-2 ${mode === m.id ? 'text-indigo-800' : 'text-slate-700'}`}>
                      {m.icon} {m.name}
                    </span>
                  </div>
                  <p className="text-xs text-slate-500 pl-6 leading-relaxed">{m.desc}</p>
                </label>
              ))}
            </div>

            <div className="grid grid-cols-2 gap-3 mb-4">
              <button 
                onClick={() => setIsRunning(!isRunning)}
                disabled={gameState.isDeadlocked}
                className={`py-3 px-4 rounded-xl font-bold text-white flex items-center justify-center gap-2 transition-all shadow-md ${isRunning ? 'bg-amber-500 hover:bg-amber-600 shadow-amber-200' : 'bg-emerald-500 hover:bg-emerald-600 shadow-emerald-200'} disabled:opacity-50 disabled:cursor-not-allowed`}
              >
                {isRunning ? <><Pause size={18}/> Pause</> : <><Play size={18}/> Play</>}
              </button>
              
              <button 
                onClick={resetState}
                className="py-3 px-4 bg-slate-200 hover:bg-slate-300 text-slate-800 font-bold rounded-xl flex items-center justify-center gap-2 transition-all"
              >
                <RefreshCw size={18}/> Reset
              </button>
            </div>

            <button 
              onClick={triggerDeadlock}
              className="w-full py-3 px-4 bg-rose-100 hover:bg-rose-200 text-rose-700 border border-rose-300 font-bold rounded-xl flex items-center justify-center gap-2 transition-all"
            >
              <AlertOctagon size={18}/> Trigger Deadlock manually
            </button>
          </div>

          {/* Logs Panel */}
          <div className="bg-slate-900 rounded-2xl shadow-inner border-2 border-slate-800 flex flex-col flex-grow overflow-hidden text-sm">
            <div className="bg-slate-950 p-3 flex items-center gap-2 text-slate-400 font-mono border-b border-slate-800 shrink-0">
              <Terminal size={16} /> Console Logs
            </div>
            <div className="p-4 overflow-y-auto flex-grow space-y-2 font-mono text-xs">
              {gameState.logs.map((log, index) => (
                <div key={index} className={`opacity-90 ${log.includes('DEADLOCK') ? 'text-rose-400 font-bold' : log.includes('EATING') ? 'text-emerald-400' : 'text-slate-300'}`}>
                  {log}
                </div>
              ))}
            </div>
          </div>
          
        </div>

        {/* Right Column: The Table */}
        <div className="xl:col-span-7 bg-white rounded-3xl shadow-lg border border-slate-200 p-8 flex items-center justify-center h-[700px] relative overflow-hidden">
          
          {/* Deadlock Overlay */}
          {gameState.isDeadlocked && (
            <div className="absolute inset-0 bg-rose-900/10 backdrop-blur-sm z-50 flex items-center justify-center">
              <div className="bg-white p-6 rounded-2xl shadow-2xl border-4 border-rose-500 text-center animate-bounce">
                <AlertOctagon size={48} className="text-rose-500 mx-auto mb-3" />
                <h3 className="text-2xl font-black text-rose-600 uppercase tracking-widest">Deadlock</h3>
                <p className="text-slate-600 mt-2 font-medium">Circular wait condition reached.</p>
                <button onClick={resetState} className="mt-4 px-6 py-2 bg-slate-900 text-white rounded-lg font-bold shadow-md hover:bg-slate-800 transition-colors">Restart</button>
              </div>
            </div>
          )}

          {/* The Physical Table */}
          <div className="w-[450px] h-[450px] rounded-full bg-amber-800 relative shadow-2xl border-8 border-amber-900">
            {/* Table Texture/Inner ring */}
            <div className="absolute inset-2 rounded-full border-2 border-amber-900/30 bg-amber-700/50"></div>
            {/* The Spaghetti */}
            <div className="absolute top-1/2 left-1/2 -translate-x-1/2 -translate-y-1/2 w-32 h-32 bg-red-800 rounded-full border-4 border-orange-200 flex items-center justify-center text-4xl shadow-inner">
               🍝
            </div>

            {/* Render Chopsticks on the table */}
            {gameState.chopsticks.map((owner, i) => {
              // Calculate chopstick position between philosophers (angle offset)
              const pos = getCoordinates(i, NUM_PHILOSOPHERS, 32, Math.PI / NUM_PHILOSOPHERS);
              
              // Only show on table if NO ONE owns it
              if (owner !== null) return null;

              return (
                <div 
                  key={`c-${i}`}
                  className="absolute text-2xl drop-shadow-md -translate-x-1/2 -translate-y-1/2 transition-all duration-500"
                  style={pos}
                >
                  <div style={{ transform: `rotate(${(i * 360 / 5) + 36}deg)` }}>🥢</div>
                  <span className="absolute text-[8px] bg-slate-800 text-white px-1 rounded -bottom-4 -left-1 opacity-50">C{i}</span>
                </div>
              );
            })}
          </div>

          {/* Render Philosophers */}
          {gameState.philosophers.map((p, i) => {
            const pos = getCoordinates(i, NUM_PHILOSOPHERS, 48);
            const stateInfo = STATES[p.state];
            
            return (
              <div 
                key={`p-${i}`}
                className="absolute flex flex-col items-center justify-center -translate-x-1/2 -translate-y-1/2 transition-all duration-300 w-32 z-10"
                style={pos}
              >
                {/* Status Bubble */}
                <div className={`mb-2 px-3 py-1 text-xs font-black uppercase tracking-wider rounded-full border-2 shadow-lg transition-colors ${stateInfo.color} ${stateInfo.text}`}>
                  {stateInfo.label} {p.state !== STATES.THINKING.id && `(${p.timeLeft})`}
                </div>
                
                {/* Philosopher Avatar */}
                <div className={`w-20 h-20 rounded-full flex items-center justify-center text-4xl shadow-xl border-4 transition-colors z-20 ${p.state === STATES.EATING.id ? 'bg-emerald-100 border-emerald-400' : 'bg-slate-100 border-slate-300'} relative`}>
                  👨‍🎓
                  <span className="absolute -bottom-3 -right-3 w-8 h-8 bg-indigo-600 text-white text-sm font-bold flex items-center justify-center rounded-full border-2 border-white shadow-md z-30">P{i}</span>
                  
                  {/* Held Chopsticks */}
                  <div className="absolute -left-4 top-4 flex flex-col gap-1 z-40">
                    {p.holding.map(cId => (
                      <span key={`held-${cId}`} className="text-xl rotate-45 drop-shadow-lg">🥢</span>
                    ))}
                  </div>
                </div>
              </div>
            );
          })}

        </div>
      </div>
    </div>
  );
}
