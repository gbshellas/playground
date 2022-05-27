package com;

import org.junit.Test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Class2Test {

    @Test
    public void test1() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            System.out.print("Please enter something:");
            String input = br.readLine();
            System.out.println("This is what you entered" + input);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }


}
