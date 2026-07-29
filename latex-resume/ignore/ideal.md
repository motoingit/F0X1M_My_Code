# Master Resume Template Requirements

The File "master-template.tex" will serve as my master resume, not a company-specific resume. Think of it as a single source of truth containing everything about my profile.

## Purpose

This master-template should contain all of my information:

### Education

B.tech(2024-current)
Inter-College(2024)
HighSchool(2022)

### Work Experience

Currently leave it oneSample Template

### Internship

Currently leave it oneSample Template

### Projects

❖ iMessage – Real Time Chat Application [more-info](https://github.com/motoingit/iMessage)
This project addresses the challenge of high-latency digital communication by delivering a highly scalable instant messaging platform. It leverages robust backend caching to seamlessly handle concurrent user loads without performance bottlenecks, ensuring secure, uninterrupted connectivity and real-time user notifications. Reduced message latency from 300ms to 45ms using Redis

❖ Lost Buddy – Lost and Found Management System [more-info](https://github.com/motoingit/F0X1M_lostAndFound_Managment)
This project solves the challenge of inefficient asset recovery by centralizing lost-and-found operations into a digital platform. It streamlines item tracking and management, eliminating manual overhead while significantly increasing the chances of quickly reuniting users with misplaced belongings.

❖ Anonyuoms Feedback [more-info](https://github.com/motoingit/nextJs_Feedback)
This project solves the challenge of inefficient asset recovery by centralizing lost-and-found operations into a digital platform. It streamlines item tracking and management, eliminating manual overhead while significantly increasing the chances of quickly reuniting users with misplaced belongings.

❖ Anonyuoms Feedback [more-info](https://github.com/motoingit/nextJs_Feedback)
This is all about anonyomus feedback

❖ News App [more-info](https://github.com/motoingit/News_app_react)
This is all about news app

❖ DSA Visualizer [more-info](https://github.com/motoingit/F7X8M_dsaVisualizer)
This is all about dsa visualizer

### Skills

#### Tech Stack

❖ Java • C++ • Python • JavaScript • TypeScript
❖ React.js • Next.js • Express.js • Node.js
❖ PostgreSQL • MongoDB • Redis
❖ Git • Docker • AWS • Linux

#### Soft Skills

❖ Audacious • Communicative

### Positions of Responsibility

❖ Hack-o-Holic | Collage | Active Teams Supervisor (Date – Apr 7, 2026)
Orchestrated the university-wide hackathon and facilitated interactive technical workshops, successfully mentoring and upskilling 300+ students in Real-World Problems. Led to 9 teams shipping MVPs, 3 winning Hackthon.

### Achievements

❖ ACM ICPC | International Collegiate Programming Contest | Regionals (Jan 2026)
Qualified for the ICPC regionals, demonstrating strong algorithmic thinking and problem-solving skills in competitive programming.

❖ Code Chef | Long Challenge | 1716 | Rank 2398 (Aug 2025)
Secured a rank of 2398 globally in CodeChef’s Long Challenge with a rating of 1716, showcasing competitive programming proficiency.

### Certifications

Extracurricular Activities
Hobbies
Awards
Publications (if any)
Competitive Programming
Any other section that may be useful.

It is not intended to be submitted directly to companies.
Instead, before applying to a company, I will duplicate this master template and create a customized one-page resume by removing or rearranging sections based on the job description.

## Design Requirements

The template should be ATS-friendly.
The design should be minimal, clean, and professional.
Avoid unnecessary graphics or decorations.
Use reusable commands/macros wherever possible.
Organize the code into logical sections so it is easy to maintain.
Avoid hardcoded values where possible (margins, spacing, colors, font sizes, etc. should be configurable).
Important Constraint

Although the master resume will contain much more than one page of content, every individual page should follow a strict one-page resume layout.

This means:

Maintain spacing and formatting appropriate for a professional one-page resume.
The document itself may naturally span multiple pages because it contains all my information.
When I create a company-specific resume, I should be able to remove unnecessary sections and immediately obtain a polished single-page resume without redesigning the layout.
Goal

The final result should function as a resume database:

One comprehensive master-template.tex.
Multiple customized resumes generated from it for different companies by selectively keeping the most relevant content.

I would make one small improvement to this workflow: instead of deleting content when tailoring a resume, comment it out or use Boolean switches. For example:

\newif\ifGoogle
\Googletrue

\newif\ifAmazon
\Amazonfalse

Then wrap sections like:

\ifGoogle
\input{sections/google-projects.tex}
\fi

This lets you generate different resumes simply by changing a few flags, without ever losing content or maintaining multiple nearly identical .tex files. It's a much more scalable approach if you plan to apply to many companies.
