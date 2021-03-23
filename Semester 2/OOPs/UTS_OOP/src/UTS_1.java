public class UTS_1 {
    String ticketCode;
    String planeName;
    String classType;
    String departure;
    String destination;
    double ticketPrice;
    double priceToPay;

    final double TWO_PERCENT = 0.02;
    final double TEN_PERCENT = 0.1;
    final double FIVE_PERCENT = 0.05;

    public double PPN( double tp ) {
        this.ticketPrice = tp;
        double ppn = TWO_PERCENT * tp;

        return ppn;
    }
    
    public double discountFivePercent() {
        return FIVE_PERCENT * ticketPrice;
    }

    public double discountTenPercent() {
        return TEN_PERCENT * ticketPrice;
    }

    public double Discount( double tp ) {
        this.ticketPrice = tp;

        if ( classType.equals("e") || classType.equals("E") ) {
            tp = discountFivePercent();
        }

        else if ( classType.equals("b") || classType.equals("B") ) {
            tp = discountTenPercent();
        }

        return tp;
    }
}