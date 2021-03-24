public class UTS_5_Fakultas extends UTS_5_Universitas {
    int code;
    String name;

    public String facultyName() {
        switch( code ) {
            case 1:
                name = "FTD";
                break;

            case 2:
                name = "Humaniora";
                break;

            default:
                name = "Fakultas tidak terdaftar";
                break;
        }

        return name;
    }
}