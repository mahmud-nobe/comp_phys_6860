## Retirement Calculator

### Inputs:
- int: Current Age
- int: Retirement Age
- double: Starting Money
- double: Current Salary
- double: Saving Percentage (% of current income saving each year)

### Assumption:
- double: annual_ROI (annual return of investment) = 5% = 0.05

### Outputs:
- Amount of money per year split out in contributions vs compounded interest part

### Saved Data:
- Terminal Output: Given Inputs and Outputs
- output.txt file: Given Inputs and Outputs


## Example:

### Inputs:
- int: Current Age: 58
- int: Retirement Age: 60
- double: Starting Money: 40k
- double: Current Salary: 100k
- double: Saving Percentage (% of current income saving each year): 20%
- annual ROI: 5%

### Output
| Age | Contribution | Previous Saving | Compound Interest (saving*0.05) | Total |
| 55 | 30K | 0 | 0 | 40k |
| 56 | 20k | 40k | 2k | 62k |
| 57 | 20k | 62k | 3.1k | 85.1k |
| 58 | 20k | 85.1k | 4.3k | 109.4k |
| 59 | 20k | 109.4k | 5.5k | 134.9k |
| 60 | 20k | 134.9k | 6.7k | 161.6k |
