package com.college.oop.java;

import java.util.Scanner;
import java.lang.Math;

public class TubeMain {
    public static void main(String[] args) {
        // Making the constructor
        Scanner input = new Scanner( System.in );
        ClsCalculate obj = new ClsCalculate();

        // Getting input from user
        System.out.print( "Input the Area (cm): " );
        obj.radius = input.nextInt();

        System.out.print( "Input the height (cm): " );
        obj.height = input.nextInt();

        // Printing the result
        System.out.println( "The result is " + obj.tube() );

        System.out.println( "The result is " + Math.round(obj.tube()) + " without decimal point." );

        // Closing the input, otherwise the resource will get leaked.
        input.close();
    }
}
