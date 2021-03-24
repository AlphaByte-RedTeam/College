public class UTS_5_Prodi extends UTS_5_Fakultas {
    int prodiCode;
    String NIM;
    String prodiName;
    String studentName;
    String grade;
    double UTS;
    private double UAS;
    private double Task;

    final double THIRTY_PERCENT = 0.3;
    final double FIVTY_PERCENT = 0.5;
    final double TWENTY_PERCENT = 0.2;

    public double getUAS() {
        return this.UAS;
    }

    public double getTask() {
        return this.Task;
    }

    public void setUAS( double uas ) {
        this.UAS = uas;
    }

    public void setTask( double task ) {
        this.Task = task;
    }

    public String prodiName() {
        switch ( prodiCode ) {
            case 1:
                prodiName = "Informatika";
                break;

            case 2:
                prodiName = "SI";
                break;

            case 3:
                prodiName = "BD";
                break;
        
            default:
                prodiName = "Prodi Tidak Terdaftar!";
                break;
        }

        return prodiName;
    }

    public double totalScore() {
        return (UTS * THIRTY_PERCENT) + (getUAS() * FIVTY_PERCENT) + (getTask() * TWENTY_PERCENT);
    }

    public String scoreGrade() {
        boolean gpaMoreThanEighty = (totalScore() >= 80);
        boolean gpaMoreThanSixty = (totalScore() >= 60);
        boolean gpaMoreThanFourty = (totalScore() >= 40);
        boolean gpaMoreThanTwenty = (totalScore() >= 20);
        boolean gpaLessThanTwenty = (totalScore() < 20);

        if ( gpaMoreThanEighty ) {
            grade = "A";
        }

        else if ( gpaMoreThanSixty ) {
            grade = "B";
        }
        
        else if ( gpaMoreThanFourty ) {
            grade = "C";
        }

        else if ( gpaMoreThanTwenty ) {
            grade = "D";
        }

        else if ( gpaLessThanTwenty ) {
            grade = "E";
        }

        return grade;
    }
}