package com.college.oop.java;

public class Currency {

    double amount;
    double code;
    double dollar;
    double euro;
    double yen;

    double currEuro( double e ) {
        this.euro = e;
        e = amount / 80;
        return e;
    }

    double currDollar( double d ) {
        this.dollar = d;
        d = amount / 70;
        return d;
    }

    double currYen( double e ) {
        this.yen = y;
        y = amount / 0.63;
        return y;
    }
}