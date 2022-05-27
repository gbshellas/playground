package com;


import static com.Class2.MYCONST1;

public class Class3 {

    protected int ErrorLevel = 1;


    public void method1() {
        System.out.println( MYCONST1);
    }

    public int getErrorLevel() {
        int a;

        try {
            method2();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }


        return ErrorLevel;
    }

    int parity;

    public void method2() throws Exception {
        String tmp_parity = "None";
        switch (tmp_parity.toLowerCase()) {
            case ("none"):
                this.parity = 0;
                break;
            case("odd"):
                this.parity = 1;
                break;
            case("even"):
                this.parity = 2;
                break;
        }

        System.out.println("parity = " + this.parity);
    }
}
