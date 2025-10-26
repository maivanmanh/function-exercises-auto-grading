#include "task.h"
#include <stdio.h>

double calculateShippingCost(double weight, char method, int zone) {

    // --- Error Handling for Invalid Weight ---
    if (weight <= 0) {
        return -1.0;
    }

    // --- Main Branch: Method ---
    if (method == 'S') {
        // Standard Shipping
        
        // Nested Branch: Zone
        if (zone == 1) {
            // Domestic
            if (weight <= 5.0) {
                return 4.99;
            } else if (weight <= 20.0) {
                return 8.99;
            } else {
                return 12.99;
            }
        } else if (zone == 2) {
            // International
            if (weight <= 2.0) {
                return 15.00;
            } else if (weight <= 10.0) {
                return 25.00;
            } else {
                return 40.00;
            }
        } else {
            // Invalid Zone
            return -1.0;
        }

    } else if (method == 'E') {
        // Express Shipping
        
        // Nested Branch: Zone
        if (zone == 1) {
            // Domestic
            if (weight <= 1.0) {
                return 10.50;
            } else if (weight <= 15.0) {
                return 18.50;
            } else {
                return 25.50;
            }
        } else if (zone == 2) {
            // International
            if (weight <= 5.0) {
                return 35.00;
            } else {
                return 50.00;
            }
        } else {
            // Invalid Zone
            return -1.0;
        }

    } else if (method == 'O') {
        // Overnight Shipping
        
        // Nested Branch: Zone
        if (zone == 1) {
            // Domestic
            if (weight <= 10.0) {
                return 30.00;
            } else {
                return 45.00;
            }
        } else if (zone == 2) {
            // International (Unsupported)
            return -1.0;
        } else {
            // Invalid Zone
            return -1.0;
        }

    } else {
        // Invalid Method
        return -1.0;
    }
}