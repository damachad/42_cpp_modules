# 🚀 Bitcoin Exchange

## 🌟 Introduction

This program focuses on handling Bitcoin exchange rates, reading data from a file, and processing user input to provide relevant exchange information. 

## ✨ Features

- **Data Loading**: Load Bitcoin exchange rate data from a CSV file.
- **Data Processing**: Process user input to provide exchange rate information.
- **Error Handling**: Robust error handling for file operations and data processing.
- **Historical Data Management**: Stores and retrieves historical exchange rate data.
- **Closest Date Matching**: Finds and uses the closest previous date's exchange rate if the exact date is not available.
- **Console Output**: Provides a clear and formatted output of the exchange rate data.

## 🛠️ Usage

1. Clone this repository;
2. Compile the program: ```make```;
3. Run: ```./btc <input_file>```;   
Make sure to have a data.csv file in the current directory with the required format:   
```
date,exchange_rate
YYYY-MM-DD,rate
```
The input_file should also be in the required format:
```
date | value
YYYY-MM-DD | value
```
