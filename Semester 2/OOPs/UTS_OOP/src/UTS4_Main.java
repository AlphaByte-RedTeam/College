import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;

public class UTS4_Main {
    static void makeLine( int length ) {
        for ( int i = 0; i < length; i++ ) {
            System.out.print( "=" );
        }
        System.out.println();
    }
    public static void main(String[] args) {
        boolean isStillRunning = true;
        
        //UTS4_Dosen dosen = new UTS4_Dosen();
        UTS4_DosenTetap dosenTetap = new UTS4_DosenTetap();
        Locale locale = new Locale( "id", "ID" );
        NumberFormat currencyFormatter = NumberFormat.getCurrencyInstance( locale );
        Scanner input = new Scanner( System.in );
        String askUser;
        byte length = 45;

        while ( isStillRunning ) {
            makeLine( length );

            System.out.print( "Input NID    : " );
            dosenTetap.NID = input.nextLine();

            System.out.print( "Input Nama   : " );
            dosenTetap.name = input.nextLine();

            System.out.print( "Jenis Kelamin: " );
            dosenTetap.gender = input.nextLine();

            dosenTetap.positions();

            System.out.print( "Gaji         : " );
            dosenTetap.salary = input.nextDouble();

            makeLine( length );

            System.out.println( "NID: " + dosenTetap.NID );
            System.out.println( "Nama Dosen: " + dosenTetap.name );
            System.out.println( "Jenis Kelamin Dosen: " + dosenTetap.gender );
            System.out.println( "Kepangkatan Dosen: " + dosenTetap.positions );
            System.out.println( "Jafung: " + currencyFormatter.format(dosenTetap.functionalAllowance()) );
            System.out.println( "Gaji Dosen: " + currencyFormatter.format(dosenTetap.salary) );
            System.out.println( "Pajak Penghasilan: " + currencyFormatter.format(dosenTetap.incomeTax()) );
            System.out.println( "Total Gaji Dosen: " + currencyFormatter.format(dosenTetap.totalSalary()));

            makeLine( length );

            System.out.println( "Apakah anda ingin mengulang kembali? [Y/T]" );
            System.out.print( ">> " );
            input.nextLine();
            askUser = input.nextLine();

            boolean no = ( askUser.equals("T") || askUser.equals("t") );

            if ( no ) {
                isStillRunning = false;
            }
        }

        input.close();
    }
}
