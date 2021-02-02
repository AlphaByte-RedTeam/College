package com.college.oop.java;

import java.util.Scanner;
import java.lang.Math;

public class CircleMain {
    public static void main(String[] args) {
        // Init Scanner to scan input
        Scanner input = new Scanner(System.in);

        // Making new object from AreaOfCircle Class
        // Constructor
        ClsFormula obj = new ClsFormula();

        System.out.print( "Input Radius (cm): " );
        // Getting input;
        obj.radius = input.nextInt();

        // Printing the result in decimal
        System.out.println( "The area of circle is: " + obj.circle() );

        /// Printing the result in whole number
        System.out.println( "The area of circle is: " + Math.round(obj.circle()) + " without decimal point." );

        // This is to close the Scanner
        // Otherwise, the scanner class is resource leaked
        input.close();
    }
}
