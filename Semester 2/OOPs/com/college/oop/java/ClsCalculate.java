package com.college.oop.java;

public class ClsCalculate {
    // Attribute
    final double Pi = 3.14;
    double radius;
    double height;
    
    // Calculate Method
    public double circle() {
        return Pi * radius * radius;
    }

    public double tube() {
        return ( Pi * radius * radius ) * height;
    }
}