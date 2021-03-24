import java.util.Scanner;

public class UTS4_DosenTetap extends UTS4_Dosen {
    final double ONE_POINT_FIVE_PERCENT = 0.015;

    public int functionalAllowance() {
        int jafung = 0;

        switch (position) {
            case 1:
                jafung = 1_000_000;
                break;

            case 2:
                jafung = 2_000_000;
                break;

            case 3:
                jafung = 3_000_000;
                break;

            case 4:
                jafung = 4_000_000;
                break;

            default:
                jafung = 0;
                break;
        }

        return jafung;
    }

    public double incomeTax() {
        double result = salary * ONE_POINT_FIVE_PERCENT;

        return result;
    }

    public double totalSalary() {
        double result = salary + functionalAllowance() - incomeTax();

        return result;
    }

    public String positions() {
        Scanner input = new Scanner( System.in );
        System.out.print( "Kepangkatan: " );
        position = input.nextInt();

        switch( position ) {
            case 1:
                positions = "AA";
                break;

            case 2:
                positions = "Lektor";
                break;

            case 3:
                positions = "Kepala Lektor";
                break;

            case 4:
                positions = "Profesor";
                break;

            default:
                positions = "Tidak Ada";
                break;
        }

        return positions;
    }
}