# Atmega32 Embedded Systems

This folder contains the embedded software project for the **Atmega32** microcontroller. It is organized into multiple layers following a modular structure for better code management and reusability. This repository aims to provide a clean, layered approach to embedded systems development.

## Folder Structure

- **APP/**: Application layer - This is where the user application code resides.
- **HAL/**: Hardware Abstraction Layer - This layer abstracts the hardware-specific details and provides functions to interact with the microcontroller's peripherals.
- **MCAL/**: Microcontroller Abstraction Layer - Contains low-level drivers for specific microcontroller peripherals.
- **LIB/**: Libraries - General-purpose drivers that are used across various parts of the system.

## Overview of Folders

### 1. **APP/**

### 2. **HAL/**
          KPAD
          LCD
  
### 3. **MCAL/**
          DIO
          ADC
          USART
          SPI
          TIMER0
          EX_INT
          GIE

### 4. **LIB/** 
          BIT_MATH.h
          STD_TYPRS.h
