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
        
        UTS4_Dosen dosen = new UTS4_Dosen();
        UTS4_DosenTetap dosenTetap = new UTS4_DosenTetap();
        Scanner input = new Scanner( System.in );
        String askUser;
        byte length = 45;

        while ( isStillRunning ) {
            makeLine( length );

            System.out.print( "Input NID: " );
            dosen.NID = input.nextLine();

            System.out.print( "Input Nama: " );
            dosen.name = input.nextLine();

            System.out.print( "Jenis Kelamin: " );
            dosen.gender = input.nextLine();

            System.out.print( "Kepangkatan: " );
            dosen.position = input.nextInt();

            System.out.print( "Gaji: " );
            dosen.salary = input.nextDouble();

            makeLine( length );

            boolean AA = ( dosen.position == 1 );
            boolean lecture = ( dosen.position == 2 );
            boolean headLecture = ( dosen.position == 3 );
            boolean professor = ( dosen.position == 4 );

            if ( AA ) {
                System.out.println( "NID: " + dosen.NID );
                System.out.println( "Nama Dosen: " + dosen.name );
                System.out.println( "Jenis Kelamin Dosen: " + dosen.gender );
                System.out.println( "Kepangkatan Dosen: " + "AA" );
                System.out.println( "Gaji Dosen: " + dosen.salary );
                System.out.println( "Pajak Penghasilan: " + dosenTetap.incomeTax( dosen.salary ) );
                System.out.println( "Total Gaji Dosen: " + dosenTetap.totalSalary( dosen.salary, dosenTetap.jafung ));
            }

            else if ( lecture ) {
                System.out.println( "NID: " + dosen.NID );
                System.out.println( "Nama Dosen: " + dosen.name );
                System.out.println( "Jenis Kelamin Dosen: " + dosen.gender );
                System.out.println( "Kepangkatan Dosen: " + "Lektor" );
                System.out.println( "Gaji Dosen: " + dosen.salary );
                System.out.println( "Pajak Penghasilan: " + dosenTetap.incomeTax( dosen.salary ) );
                System.out.println( "Total Gaji Dosen: " + dosenTetap.totalSalary( dosen.salary, dosenTetap.jafung ));
            }

            else if ( headLecture) {
                System.out.println( "NID: " + dosen.NID );
                System.out.println( "Nama Dosen: " + dosen.name );
                System.out.println( "Jenis Kelamin Dosen: " + dosen.gender );
                System.out.println( "Kepangkatan Dosen: " + "Kepala Lektor" );
                System.out.println( "Gaji Dosen: " + dosen.salary );
                System.out.println( "Pajak Penghasilan: " + dosenTetap.incomeTax( dosen.salary ) );
                System.out.println( "Total Gaji Dosen: " + dosenTetap.totalSalary( dosen.salary, dosenTetap.jafung ));
            }

            else if ( professor ) {
                System.out.println( "NID: " + dosen.NID );
                System.out.println( "Nama Dosen: " + dosen.name );
                System.out.println( "Jenis Kelamin Dosen: " + dosen.gender );
                System.out.println( "Kepangkatan Dosen: " + "Profesor" );
                System.out.println( "Gaji Dosen: " + dosen.salary );
                System.out.println( "Pajak Penghasilan: " + dosenTetap.incomeTax( dosen.salary ) );
                System.out.println( "Total Gaji Dosen: " + dosenTetap.totalSalary( dosen.salary, dosenTetap.jafung ));
            }

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