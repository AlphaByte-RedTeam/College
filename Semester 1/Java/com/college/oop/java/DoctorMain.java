package com.college.oop.java;

import java.text.NumberFormat;
import java.util.Scanner;
//import javax.swing.JOptionPane;

public class DoctorMain {

    static void makeLine( int length ) {
        for ( int i = 0; i < length; i++ ) {
            System.out.print( "=" );
        }
        System.out.print( "\n" );
    }

    public static void main(String[] args) {

        byte data;
        String doctorID;
        String doctorName;
        String name;
        
        makeLine( 40 );
        Scanner read = new Scanner( System.in );
        Doctor objDoctor = new Doctor();
        NumberFormat currency = NumberFormat.getCurrencyInstance();

        System.out.println( "Input your name below, " );
        System.out.print( ">> ");
        name = read.nextLine();

        makeLine( 40 );
        System.out.println( "        Welcome " + name );
        System.out.println( "     Doctor Total Salary Program!" );
        makeLine( 40 );

        System.out.print( "How many data you want to input: " );
        data = read.nextByte();

        makeLine( 40 );

        for ( int i = 0; i < data; i++ ) {
            System.out.print( "Input doctor ID: " );
            read.nextLine();
            doctorID = read.nextLine();
                
            System.out.print( "Input doctor name: " );
            doctorName = read.nextLine();
            //read.nextLine();

            while( true ) {
                System.out.print( "Input salary: " );
                objDoctor.salary = read.nextDouble();
    
                if ( objDoctor.salary >= 1_000_000 ) {
                    break;
                }
                System.out.println( "Enter value larger than 1 million!\n" );
            }

            makeLine( 40 );

            System.out.println( "Doctor ID   : " + doctorID );
            System.out.println( "Doctor Name : " + doctorName );
            System.out.println( "Salary      : " + currency.format(objDoctor.salary) );
            System.out.println( "Allowance   : " + currency.format(objDoctor.allowance( objDoctor.salary )) );
            System.out.println( "Total Salary: " + currency.format((objDoctor.totalSalary())) );

            makeLine( 40 );
        }
        
        read.close();
    }
}