package com.college.oop.java;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.*;

public class TenantMain {

    static void makeLine( int length ) {
        for ( int i = 0; i < length; i++ ) {
            System.out.print( "=" );
        }
        System.out.println( "" );
    }

    public static void main(String[] args) {
        Scanner read = new Scanner( System.in );
        Tenant tenant = new Tenant();
        DecimalFormat percent = new DecimalFormat("#%");
        DecimalFormat IDR = (DecimalFormat) DecimalFormat.getCurrencyInstance();
        DecimalFormatSymbols formatIDR = new DecimalFormatSymbols();
        
        formatIDR.setCurrencySymbol( "IDR" );
        formatIDR.setMonetaryDecimalSeparator( '.' );
        formatIDR.setGroupingSeparator( ',' );
        IDR.setDecimalFormatSymbols( formatIDR );

        int length = 45;
        
        makeLine( length );
        System.out.println( "\t  --Pengisian Data Penyewa--" );
        makeLine( length );

        System.out.print( "ID: " );
        tenant.IDpenyewa = read.nextLine();

        System.out.print( "Nama: " );
        tenant.nama = read.nextLine();

        System.out.print( "Alamat: " );
        tenant.alamat = read.nextLine();

        System.out.print( "No.KTP: " );
        tenant.KTP = read.nextLine();
        
        System.out.print( "Nomor Telepon: " );
        tenant.KTP = read.nextLine();

        System.out.print( "Jenis Kendaraan: " );
        tenant.jenKendaraan = read.nextLine();

        System.out.print( "Nomor Plat Kendaraan: " );
        tenant.noPlat = read.nextLine();

        System.out.print( "Lama Sewa (Hari): " );
        tenant.lamaSewa = read.nextInt();

        System.out.print( "Biaya Sewa: " );
        tenant.biayaSewa = read.nextInt();

        makeLine( length );
        System.out.println( "\t\t--Data Penyewa--" );
        makeLine( length );

        System.out.println( "ID                : " + tenant.IDpenyewa );
        System.out.println( "Nama              : " + tenant.nama );
        System.out.println( "Alamat            : " + tenant.alamat );
        System.out.println( "No.KTP            : " + tenant.KTP );
        System.out.println( "No.Telepon        : " + tenant.noTelp );
        System.out.println( "Jenis Kendaraan   : " + tenant.jenKendaraan );
        System.out.println( "No.Plat Kendaraan : " + tenant.noPlat );
        System.out.println( "Lama Sewa         : " + tenant.lamaSewa + " hari" );
        makeLine( length );

        if ( tenant.lamaSewa >= tenant.TUJUH_HARI  ) {
            System.out.println( "Anda mendapatkan diskon " + percent.format(tenant.LIMA_PERSEN) );
            System.out.printf( "Harga Diskon: IDR%,.0f\n", tenant.PotonganHarga(tenant.lamaSewa, tenant.biayaSewa) );
            System.out.printf( "Biaya Sewa Sebelum Diskon: IDR%,.0f\n", tenant.HargaSewa(tenant.lamaSewa, tenant.biayaSewa) );
            System.out.printf( "Biaya Sewa Sesudah Diskon: IDR%,.0f\n", tenant.HargaDiskon(tenant.lamaSewa, tenant.biayaSewa) );
            System.out.printf( "PPN: IDR%,.0f\n", tenant.PPN(tenant.lamaSewa, tenant.biayaSewa));
            System.out.printf( "Total Biaya Sewa Yang Harus Dibayar: IDR%,.0f\n", tenant.Bayar(tenant.lamaSewa, tenant.biayaSewa) );
        }

        else if ( tenant.lamaSewa >= tenant.LIMA_HARI ) {
            System.out.println( "Anda mendapatkan diskon " + percent.format(tenant.TIGA_PERSEN) );
            System.out.printf( "Harga Diskon: IDR%,.0f\n", tenant.PotonganHarga(tenant.lamaSewa, tenant.biayaSewa) );
            System.out.printf( "Biaya Sewa Sebelum Diskon: IDR%,.0f\n", tenant.HargaSewa(tenant.lamaSewa, tenant.biayaSewa) );
            System.out.printf( "Biaya Sewa Sesudah Diskon: IDR%,.0f\n", tenant.HargaDiskon(tenant.lamaSewa, tenant.biayaSewa) );
            System.out.printf( "PPN: IDR%,.0f\n", tenant.PPN(tenant.lamaSewa, tenant.biayaSewa));
            System.out.printf( "Total Biaya Sewa Yang Harus Dibayar: IDR%,.0f\n", tenant.Bayar(tenant.lamaSewa, tenant.biayaSewa) );
        }

        else if ( tenant.lamaSewa >= tenant.TIGA_HARI ) {
            System.out.println( "Anda mendapatkan diskon " + percent.format(tenant.DUA_HARI) );
            System.out.printf( "Harga Diskon: IDR%,.0f\n", tenant.PotonganHarga(tenant.lamaSewa, tenant.biayaSewa) );
            System.out.printf( "Biaya Sewa Sebelum Diskon: IDR%,.0f\n", tenant.HargaSewa(tenant.lamaSewa, tenant.biayaSewa) );
            System.out.printf( "Biaya Sewa Sesudah Diskon: IDR%,.0f\n", tenant.HargaDiskon(tenant.lamaSewa, tenant.biayaSewa) );
            System.out.printf( "PPN: IDR%,.0f\n", tenant.PPN(tenant.lamaSewa, tenant.biayaSewa));
            System.out.printf( "Total Biaya Sewa Yang Harus Dibayar: IDR%,.0f\n", tenant.Bayar(tenant.lamaSewa, tenant.biayaSewa) );
        }

        else if ( tenant.lamaSewa <= tenant.DUA_HARI ) {
            System.out.println( "Tidak mendapatkan diskon" );
            System.out.printf( "PPN: IDR%,.0f\n", tenant.PPN(tenant.lamaSewa, tenant.biayaSewa));
            System.out.printf( "Total Biaya Sewa Yang Harus Dibayar: IDR%,.0f\n", tenant.Bayar(tenant.lamaSewa, tenant.biayaSewa) );
        }

        read.close();
    }
}