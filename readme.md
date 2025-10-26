## Assignment: Advanced Shipping Cost Calculator

Your task is to implement a C function that calculates the shipping cost for a package based on a complex set of business rules. You must implement all logic, including error handling, within this single function.

### Function Prototype

You must implement the function with the following prototype:
`double calculateShippingCost(double weight, char method, int zone);`

### Parameter Definitions

* **`double weight`**: The weight of the package in kilograms (kg).
* **`char method`**: A character code for the shipping method.
    * `'S'` for Standard
    * `'E'` for Express
    * `'O'` for Overnight
* **`int zone`**: An integer code for the destination zone.
    * `1` for Domestic
    * `2`for International

### Logic Requirements

The function must return the calculated cost as a `double` by correctly nesting the following rules:

1.  **If the `method` is 'S' (Standard):**
    * If the `zone` is **1 (Domestic)**, the cost is based on weight:
        * $4.99 for 5.0 kg or less.
        * $8.99 for more than 5.0 kg up to and including 20.0 kg.
        * $12.99 for more than 20.0 kg.
    * If the `zone` is **2 (International)**, the cost is based on weight:
        * $15.00 for 2.0 kg or less.
        * $25.00 for more than 2.0 kg up to and including 10.0 kg.
        * $40.00 for more than 10.0 kg.

2.  **If the `method` is 'E' (Express):**
    * If the `zone` is **1 (Domestic)**, the cost is based on weight:
        * $10.50 for 1.0 kg or less.
        * $18.50 for more than 1.0 kg up to and including 15.0 kg.
        * $25.50 for more than 15.0 kg.
    * If the `zone` is **2 (International)**, the cost is based on weight:
        * $35.00 for 5.0 kg or less.
        * $50.00 for more than 5.0 kg.

3.  **If the `method` is 'O' (Overnight):**
    * If the `zone` is **1 (Domestic)**, the cost is based on weight:
        * $30.00 for 10.0 kg or less.
        * $45.00 for more than 10.0 kg.
    * If the `zone` is **2 (International)**, this combination is **not supported**.

### Error Handling

The function must return `-1.0` for any of the following error conditions:

* The `weight` is zero or negative.
* The `method` character is not 'S', 'E', or 'O'.
* The `zone` is not 1 or 2.
* The shipping combination is unsupported (e.g., Overnight International).