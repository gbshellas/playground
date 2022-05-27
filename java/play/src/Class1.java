import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Class1 {
    public int debugTraceLevel = 0;

    public static void main(String args[]) {
        // (new Class1()).method8();


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            System.out.print("Please enter something:");
            String input = br.readLine();
            System.out.println("This is what you entered" + input);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        //System.out.println(Class1.class.getSimpleName());

    }

    public void method1() {
        try {
            String propDebugTraceLevel = null;

            // propDebugTraceLevel = (String) this.jposEntry.getPropertyValue("debugTraceLevel");
            //if(propDebugTraceLevel == null)
             //   propDebugTraceLevel = "";

            debugTraceLevel = Integer.parseInt(propDebugTraceLevel);;
        } catch (Exception ex) {
            System.err.println("Error reading property debugTraceLevel, setting to default level 0. " + ex.toString());
            debugTraceLevel = 0;
        }
    }

    public void method2() {
        int [] mybuffer = new int[11];

        int i=0;

        while( i < 10 ) {
            mybuffer[i++] = i;
            mybuffer[i] = 999;
        }

        mybuffer = new int[11];

        i = 0;
        while( i < 10 ) {
            mybuffer[++i] = i;
            mybuffer[i] = 999;
        }


    }

    public void method3() {
        if(Configuration.DEBUG) {
            System.out.println("Debug Activated");
        }
    }

    public String [] method4() {
        String [] returnValue = new String[5];
        returnValue[0] = "Hello world";
        return returnValue;
    }

    public void method5() {
        String [] ret = method4();
        System.out.println(ret);
    }

    class ReturnCode {
        public String returnValue;
        public String [] returnArray;
    }


    public void method6() {
        ReturnCode rc = new ReturnCode();
        method7(rc);
    }

    public void method7(ReturnCode rc) {
        rc.returnValue = "Hello World Parts";
        rc.returnArray = rc.returnValue.split(" ");
    }

    int parity;

    public void method8() {
        String tmp_parity = "even";
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
