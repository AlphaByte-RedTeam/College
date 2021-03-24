public class UTS4_DosenTetap extends UTS4_Dosen {
    final double ONE_POINT_FIVE_PERCENT = 0.015;
    double jafung;

    public double functionalAllowance( double jf ) {
        double jafung = this.jafung;

        boolean AA = ( position == 1 );
        boolean lecture = ( position == 2 );
        boolean headLecture = ( position == 3 );
        boolean professor = ( position == 4 );

        if ( AA ) {
            this.jafung = 1000000;
        }

        else if ( lecture ) {
            this.jafung = 2000000;
        }

        else if ( headLecture ) {
            this.jafung = 3000000;
        }

        else if ( professor ) {
            this.jafung = 4000000;
        }

        return jafung;
    }

    public double incomeTax( double salary ) {
        double result = salary * ONE_POINT_FIVE_PERCENT;

        return result;
    }

    public double totalSalary( double salary, double jafung ) {
        double result = (salary + functionalAllowance( jafung )) - incomeTax( salary );

        return result;
    }
}