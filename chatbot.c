# Project 3: Rule-Based Chatbot (C Language)

## 📌 Description
This project is a simple chatbot built using C.  
It follows *rule-based responses* — meaning it replies based on keywords detected in the user input.

## 🧠 Features
- Responds to:
  - hello / hi
  - how are you
  - what is your name
  - time
  - thanks
  - bye (exit)
- Uses:
  - string matching
  - loops
  - conditional rules

## 🛠️ How It Works
The chatbot checks the user's message using:
- `strcmp()` for exact match  
- `strstr()` for keyword detection  

Example:
```c
if (strstr(input, "hello")) {
    printf("Bot: Hello! How can I help you?\n");
}
