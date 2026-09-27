import { useCallback, useEffect, useState, useRef, useMemo } from "react";
import "./index.css";



export default function App() {

  const selectColor = {
    red: "bg-red-500",
    green: "bg-green-500",
    blue: "bg-blue-500",
  };

  const [bgColor, setBgColor] = useState("bg-blue-500");
  const [inputValue, setInputValue] = useState("Start Making Password Here");

  const [isSymbol, setIsSymbol] = useState(false);
  const [isNumber, setIsNumber] = useState(false);
  const [currLen, setCurrLen] = useState(8);

   const inputField = useRef(null);

  const fun = (value) => {
    setBgColor(value);
  };

  //return pass
  const passGen = useCallback(() => {
    const letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const numbers = "0123456789";
    const symbols = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    let characters = letters;
    if(isSymbol) characters += symbols;
    if(isNumber) characters += numbers;

    let password = "";
    for (let index = 0; index < currLen; index++) {
      let idx = Math.floor(Math.random() * characters.length)
      password += characters[idx];
    }

    setInputValue(password);
  }, [isNumber, isSymbol, currLen]);

  useEffect(() => {
    passGen();
  }, [passGen]);

 

  const copyBoard = useCallback( async () => {
    //WARN: this is serverside so we have windowobject , but not in Serverside
    // window.navigator.clipboard.writeText(inputValue);
    
    // inputField.current?.focus();
    inputField.current?.select();
    inputField.current?.setSelectionRange(0, 5);
    await navigator.clipboard.writeText(inputValue);
    // window.Clipboard.whaaat;
  }, [inputValue]);

  return (
    <div className={`min-h-screen flex items-center justify-center ${bgColor}`}>
      <div className="w-full max-w-md rounded-2xl bg-white/10 backdrop-blur-md border border-white/20 shadow-2xl p-6 space-y-6">
        <h2 className="text-2xl font-bold text-center">Password Generator</h2>

        {/* Password Output */}
        <div className="flex overflow-hidden rounded-lg">
          <input
            style={{background: 'white'}}
            ref={inputField}
            id="input-field"
            type="text"
            value={inputValue}
            readOnly
            className="flex-1 px-4 py-2 outline-none text-black"
          />

          <button
            id="copyBtn"
            className="px-4 bg-blue-600 text-white hover:bg-blue-700 transition"
            onClick={copyBoard}
          >
            COPY
          </button>
        </div>

        {/* Options */}
        <div className="space-y-4">
          <div className="flex items-center justify-between">
            <label>Include Symbols</label>

            <input
              type="checkbox"
              onChange={() => setIsSymbol((prev) => !prev)}
            />
          </div>

          <div className="flex items-center justify-between">
            <label>Include Numbers</label>

            <input
              type="checkbox"
              onChange={() => setIsNumber((prev) => !prev)}
            />
          </div>

          <div className="space-y-2">
            <div className="flex justify-between">
              <label>Password Length</label>

              <span>{currLen}</span>
            </div>

            <input
              type="range"
              min={8}
              max={64}
              value={currLen}
              className="w-full cursor-pointer"
              onChange={(e) => setCurrLen(Number(e.target.value))}
            />
          </div>
        </div>
      </div>

      {/* Background Color Selector */}
      <div className="fixed bottom-6 inset-x-0 flex justify-center gap-4">
        <button
          onClick={() => fun(selectColor.red)}
          className={`h-12 w-12 rounded-full shadow-lg transition hover:scale-110 ${selectColor.red}`}
        />

        <button
          onClick={() => fun(selectColor.green)}
          className={`h-12 w-12 rounded-full shadow-lg transition hover:scale-110 ${selectColor.green}`}
        />

        <button
          onClick={() => fun(selectColor.blue)}
          className={`h-12 w-12 rounded-full shadow-lg transition hover:scale-110 ${selectColor.blue}`}
        />
      </div>
    </div>
  );
}
