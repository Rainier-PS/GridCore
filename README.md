# GridCore

> GridCore is a minimalist reaction-based game system built on a 2×2 LED grid with 4 buttons. Modular. Expandable. Fun.

![GridCore Board](image%2FGridCore_Render_Front.png)

## What is GridCore?

GridCore is a lightweight, open-source mini game console using only 4 buttons and a 2×2 LED grid. GridCore is designed to be fun, hackable, and extendable. It runs simple games like reaction challenges with plans for more in future updates. (more games)

## Images

### Schematic
![Schematic](image%2FSchematics.png)

### PCB Layout
![PCB Layout](image%2FPCB.png)

### PCB Front (Render)
![PCB Front Render](image%2FPCB_Render_Front.png)

### PCB Back (Render)
![PCB Back Render](image%2FPCB_Render_Back.png)

### GridCore Board - Front
![GridCore Board Front](image%2FGridCore_Render_Front.png)

### GridCore Board - Back
![GridCore Board Back](image%2FGridCore_Render_Back.png)

## Features

- Reaction-based game logic that gets harder with each level
- Built-in splash screen animation
- MX keys 4-button control
- Organized, human-readable code
- Easily expandable architecture for additional games/tools

## How to Play

- Watch for a random LED to light up.
- Press the corresponding button as fast as possible.
- Get it right? You level up and it gets faster.
- Miss or timeout? The game restarts.

**Button–LED Layout**  
(Button position ≠ LED index)

| Button No. | Position     | LED No. | LED Position    |
|------------|--------------|---------|-----------------|
| Button 1   | Top Left     | LED 3   | Upper Right     |
| Button 2   | Top Right    | LED 2   | Upper Left      |
| Button 3   | Bottom Left  | LED 1   | Lower Left      |
| Button 4   | Bottom Right | LED 4   | Lower Right     |

## Future Plans

- Add multiple minigames (reaction, memory, binary input)
- Tool modes (timer, counter, morse trainer, etc)

## Getting Started

### 1. Flash the Code

Upload the `GridCore.ino` sketch to your board using Arduino IDE or PlatformIO.

### 2. Wiring

| Function | GPIO Pin | Notes         |
|----------|----------|---------------|
| Button 1 | GPIO26   | Pull-down     |
| Button 2 | GPIO27   | Pull-down     |
| Button 3 | GPIO28   | Pull-down     |
| Button 4 | GPIO29   | Pull-down     |
| LED 1    | GPIO0    | Lower Left    |
| LED 2    | GPIO7    | Upper Left    |
| LED 3    | GPIO6    | Upper Right   |
| LED 4    | GPIO1    | Lower Right   |

> **Note**  
> This project has passed both ERC (Electrical Rule Check) and DRC (Design Rule Check) with no errors. All submission requirements for Pathfinder have been completed.
