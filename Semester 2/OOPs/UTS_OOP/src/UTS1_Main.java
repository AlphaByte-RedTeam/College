import java.text.NumberFormat;
import java.util.Locale;
import javax.swing.*;


public class UTS1_Main {
    public static void main(String[] args) {

        UTS_1 uts;
        final JDialog dialog = new JDialog();
        Locale locale = new Locale( "id", "ID" );
        NumberFormat currencyFormatter = NumberFormat.getCurrencyInstance( locale );
        dialog.setAlwaysOnTop( true );
        double priceToPay;
        int askUser;
        
        do {
            uts = new UTS_1();

            uts.ticketCode = JOptionPane.showInputDialog( "Kode Tiket" );
            uts.planeName = JOptionPane.showInputDialog( "Nama Pesawat" );
            uts.classType = JOptionPane.showInputDialog( "Tipe Kelas" );        
            uts.departure = JOptionPane.showInputDialog( "Keberangkatan" );
            uts.destination = JOptionPane.showInputDialog( "Tujuan" );
            uts.ticketPrice = Double.parseDouble( JOptionPane.showInputDialog( "Input Harga Tiket" ) );

            priceToPay = ( uts.ticketPrice + uts.PPN( uts.ticketPrice ) ) - ( uts.Discount( uts.ticketPrice ) );

            if ( uts.classType.equals("e") || uts.classType.equals("E") ) {
                String ppn = currencyFormatter.format(uts.PPN( uts.ticketPrice ));
                String discount = currencyFormatter.format(uts.Discount( uts.ticketPrice ));
                String totalPay = currencyFormatter.format(priceToPay);

                JOptionPane.showMessageDialog(
                null,
                "Kode Tiket     : " + uts.ticketCode +
                "\nNama Pesawat : " + uts.planeName +
                "\nKelas        : " + "Ekonomi" +
                "\nKeberangkatan: " + uts.departure +
                "\nTujuan       : " + uts.destination +
                "\nBiaya Tiket  : " + currencyFormatter.format( uts.ticketPrice ) +
                "\n\n"              +
                "\nPPN          : " + ppn +
                "\nDiskon       : " + discount +
                "\nTotal Bayar  : " + totalPay
                );
            }

            else if ( uts.classType.equals("b") || uts.classType.equals("B") ) {
                String ppn = currencyFormatter.format(uts.PPN( uts.ticketPrice ));
                String discount = currencyFormatter.format(uts.Discount( uts.ticketPrice ));
                String totalPay = currencyFormatter.format(priceToPay);

                JOptionPane.showMessageDialog(
                null,
                "Kode Tiket     : " + uts.ticketCode +
                "\nNama Pesawat : " + uts.planeName +
                "\nKelas        : " + "Bisnis" +
                "\nKeberangkatan: " + uts.departure +
                "\nTujuan       : " + uts.destination +
                "\nBiaya Tiket  : " + currencyFormatter.format( uts.ticketPrice ) +
                "\n\n"              +
                "\nPPN          : " + ppn +
                "\nDiskon       : " + discount +
                "\nTotal Bayar  : " + totalPay
                );
            }

            else {
                JOptionPane.showMessageDialog(
                null,
                "Kode Tiket     : " + uts.ticketCode +
                "\nNama Pesawat : " + uts.planeName +
                "\nKelas        : " + "Kelas tidak valid, mohon masukkan ulang kembai setelah tampilan ini!" +
                "\nKeberangkatan: " + uts.departure +
                "\nTujuan       : " + uts.destination +
                "\nBiaya Tiket  : " + String.format("%.0f", uts.ticketPrice) +
                "\n\n"              +
                "\nPPN          : " + String.format("%.0f", uts.PPN( uts.ticketPrice )) +
                "\nDiskon       : " + "0" +
                "\nTotal Bayar  : " + String.format("%.0f", priceToPay)
                );
            }

            askUser = JOptionPane.showConfirmDialog( dialog, "Apakah anda mau mengulang kembali?", "Ask User", JOptionPane.YES_NO_OPTION );
        } while( askUser == JOptionPane.YES_OPTION );
    }
}