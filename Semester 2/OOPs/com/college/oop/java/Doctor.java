package com.college.oop.java;

import java.util.Scanner;

public class Doctor {
    double salary;
    final double TEN_PERCENT = 0.1;

    Scanner scan = new Scanner( System.in );

    // Method
    double allowance( double s ) {
        this.salary = s;
        
        return TEN_PERCENT * s;
    }

    double totalSalary() {
        return salary + allowance( salary );
    }
}