import java.util.Scanner;

public class UTS5_Main {
    static void makeline( int length ) {
        for ( int i = 0; i < length; i++ ) {
            System.out.print( "=" );
        }
        System.out.println();
    }
    public static void main(String[] args) {
        UTS_5_Universitas universitas = new UTS_5_Universitas();
        UTS_5_Fakultas fakultas = new UTS_5_Fakultas();
        UTS_5_Prodi prodi = new UTS_5_Prodi();
        Scanner input = new Scanner( System.in );
        String askUser;
        boolean isStillRunning = true;
        byte length = 45;

        while ( isStillRunning ) {
            makeline( length );
            System.out.println( "\t     Data Universitas\n" );
            
            System.out.print( "Input Nama Universitas: " );
            universitas.name = input.nextLine();

            System.out.print( "Input Alamat Universitas: " );
            universitas.address = input.nextLine();

            System.out.print( "Input No.Telepon: " );
            universitas.phoneNumber = input.nextLine();

            System.out.print( "Input Pimpinan Universitas: " );
            universitas.headmaster = input.nextLine();

            makeline( length );

            System.out.println( "\t     Data Fakultas\n" );

            System.out.println( "Input Kode Fakultas [Pilih dari angka 1 - 2]" );
            System.out.print( ">> " );
            fakultas.code = input.nextInt();

            makeline( length );

            System.out.println( "\t     Data Prodi\n" );

            System.out.println( "Input Kode Prodi [Pilih dari angka 1 - 4]" );
            System.out.print( ">> " );
            prodi.prodiCode = input.nextInt();

            System.out.print( "\nInput Nama Mahasiswa: " );
            input.nextLine();
            prodi.studentName = input.nextLine();
            
            System.out.print( "Input NIM Mahasiswa: " );
            prodi.NIM = input.nextLine();

            System.out.print( "Input Nilai Tugas: " );
            prodi.setTask( input.nextDouble() );

            System.out.print( "Input Nilai UTS: " );
            prodi.UTS = input.nextDouble();

            System.out.print( "Input Nilai UAS: " );
            prodi.setUAS( input.nextDouble() );

            makeline( length );

            System.out.println( "\tHasil Rekap Data" );

            System.out.println( "Universitas: " + universitas.name );
            System.out.println( "Alamat: " + universitas.address );
            System.out.println( "No. Telp: " + universitas.phoneNumber );
            System.out.println( "Pimpinan: " + universitas.headmaster );
            System.out.println( "Fakultas: " + fakultas.facultyName() );
            System.out.println( "Prodi: " + prodi.prodiName() );
            System.out.println( "Nama Mahasiswa: " + prodi.studentName );
            System.out.println( "NIM Mahasiswa: " + prodi.NIM );
            System.out.println( "Nilai Tugas: " + prodi.getTask() );
            System.out.println( "Nilai UTS: " + prodi.UTS );
            System.out.println( "Nilai UAS: " + prodi.getUAS() );
            System.out.println( "Total Nilai: " + prodi.totalScore() );
            System.out.println( "Grade Nilai: " + prodi.scoreGrade() );
            
            System.out.println( "Apakah anda mau mengulang kembali? [Y/T]" );
            System.out.print( ">> " );
            input.next();
            askUser = input.nextLine();
        }
        input.close();
    }
}