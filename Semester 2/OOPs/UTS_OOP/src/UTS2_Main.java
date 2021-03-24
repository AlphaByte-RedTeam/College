import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;

public class UTS2_Main {

    static void makeLine( int length ) {
        for ( int i = 0; i < length; i++ ) {
            System.out.print( "=" );
        }
        System.out.print( "\n" );
    }

    public static void main(String[] args) {
        UTS_2 heavyEquipment = new UTS_2();
        UTS_2 tenant = new UTS_2();
        Scanner input = new Scanner( System.in );
        Locale locale = new Locale( "id", "ID" );
        NumberFormat currencyFormatter = NumberFormat.getCurrencyInstance( locale );
        boolean isStillRunning = true;

        int length = 40;
        String askUser;

        while ( isStillRunning ) {
            makeLine( length );
            
            System.out.print( "Masukkan Kode Alat Berat   : " );
            heavyEquipment.code = input.nextLine();
            
            System.out.print( "Masukkan Nama Alat Berat   : " );
            heavyEquipment.name = input.nextLine();

            System.out.print( "Masukkan Biaya Sewa /jam   : " );
            heavyEquipment.setRentFeePerHour( input.nextDouble() );

            System.out.print( "Masukkan Lama Sewa /jam    : " );
            heavyEquipment.setRentDurationPerHour( input.nextDouble() );

            System.out.print( "Masukkan Nama Penyewa      : " );
            input.nextLine();
            tenant.name = input.nextLine();

            System.out.print( "Masukkan Nomor KTP Penyewa : " );
            tenant.KTP = input.nextLine();

            makeLine( length );

            System.out.println( "\t     --Data Penyewa--\n" );
            System.out.println( "Kode Alat Berat: " + heavyEquipment.code );
            System.out.println( "Nama Alat Berat: " + heavyEquipment.name );
            System.out.println( "Biaya Sewa /jam: " + currencyFormatter.format(heavyEquipment.getRentFeePerHour()) + " /jam" );
            System.out.println( "Lama Sewa /jam : " + String.format("%.0f", heavyEquipment.getRentDurationPerHour()) + " jam" );
            System.out.println( "Sub Total Sewa : " + currencyFormatter.format(heavyEquipment.rentSubTotal()) );
            System.out.println( "Diskon         : " + currencyFormatter.format(heavyEquipment.rentDiscount(heavyEquipment.discount)) );
            System.out.println( "Total Biaya    : " + currencyFormatter.format(heavyEquipment.rentTotalPrice()) );

            makeLine( length );

            System.out.println( "Apakah anda mau mengulang kembali? [Y/T]" );
            System.out.print( ">> " );
            askUser = input.nextLine();

            if ( askUser.equals( "T" ) || askUser.equals( "t" ) ) {
                isStillRunning = false;
            }
        }
        input.close();
    }
}