package com.college.oop.java;

import java.util.*;
import java.text.DecimalFormat;

public class CurrencyMain {
    
    static void makeLine( int length ) {
        for ( int i = 0; i < length; i++ ) {
            System.out.print( "-" );
        }

        System.out.print( "\n" );
    }

    public static void main(String[] args) {
        DecimalFormat objFormat = new DecimalFormat( "##.##" );
        Scanner input = new Scanner( System.in );
        Currency currency = new Currency();

        makeLine( 40 );

        System.out.println( "Welcom to the currency converter program" );
        System.out.println( "Which currency you want to convert?" );
        System.out.println( "1. Euro\n2.Yen\n3.Dollar" );
        System.out.print( ">> " );
        currency.code = input.nextInt();

        makeLine( 40 );

        System.out.println( "How much money you want to convert?" );
        System.out.print( ">> " );
        currency.amount = input.nextInt();

        makeLine( 40 );

        if ( currency.code = 1 ) {
            currency.currDollar( currency.dollar );
            System.out.println( currency.amount + " euro is equal to = " + objFormat.format( dollar ) + " Dollar" );
        }


        input.close();
    }
}