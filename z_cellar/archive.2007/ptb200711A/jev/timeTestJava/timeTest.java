//--------------------------------UNCLASSIFIED----------------------------------
// File: timeTest.java
// Desc: This file contains the code for the timeTest class.
// Hist: When       Who  What
//       02/04/2002 ptb  Initial Code.
//--------------------------------UNCLASSIFIED----------------------------------

// Import Files.
// -----------------------------------------------------------------------------
import java.awt.*;
import java.awt.event.*;
import java.lang.*;
import java.lang.Long;
import java.io.*;
import java.util.*;
import javax.swing.*;
import javax.swing.event.*;
//import jniOrbitUtils.;

public class timeTest
{

// JNI method.
// -----------------------------------------------------------------------------
    static
    {
	System.loadLibrary("libjniOrbitUtils");
    }
    static
    {
	System.out.println("Static Hello test.");
    }


// Main method.
// -----------------------------------------------------------------------------
  public static void main(String args[])
  {
    long time;
    double phiGrn;
    int ii;
    short c;
    boolean flag=false;
    String str1 = new String();
    String str2 = new String();

    // Set up standard in.
    // -------------------------------------------------------------------------
    DataInputStream dataIn = new DataInputStream(System.in);

    System.out.println("Hello from timeTest.");
    while(!flag)
    {
    try{
	c = dataIn.readShort();
	System.out.println(c);
    }
    catch( IOException e ) { 
	System.out.println("Ooops.");
	flag = true;
    }
    }

    //Set look and Feel.
    // -------------------------------------------------------------------------
    try
    {
	UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
    }
    catch (Exception e){System.out.println("Barfed on UIManager");}

    // Create the label.
    // -------------------------------------------------------------------------
    time = libjniOrbitUtils.iccGetTime();
    phiGrn = libjniOrbitUtils.iccGetPhiGrn(time);

    JLabel label1 = new JLabel("TIME: " + time);
    JLabel label2 = new JLabel("PhiGrn: " + phiGrn);
    
    // Create the button.
    // -------------------------------------------------------------------------
    JButton button = new JButton("Quit");
    button.setMnemonic(KeyEvent.VK_Q);
    button.addActionListener( new ActionListener()
    {
      public void actionPerformed(ActionEvent e)
      {
        System.exit(0);
      }
    });

    // Create the plot panel.
    // -------------------------------------------------------------------------
    plotPanel ploter = new plotPanel();

    // Create the panel.
    // -------------------------------------------------------------------------
    JPanel pane = new JPanel();
    pane.setBorder(BorderFactory.createEmptyBorder(30,30,10,30));
    pane.setLayout(new GridLayout(4,1));
    pane.add(button);
    pane.add(label1);
    pane.add(label2);
    pane.add(ploter);
    
    // Create the frame.
    // -------------------------------------------------------------------------
    JFrame theFrame = new JFrame("icc Time Test");
    theFrame.getContentPane().add(pane, BorderLayout.CENTER);
    theFrame.addWindowListener(new WindowAdapter()
    {
      public void windowClosing(WindowEvent e)
      {
        System.exit(0);
      }
    });
    theFrame.pack();
    theFrame.setVisible(true);

    // Do the time loop.
    // -------------------------------------------------------------------------
    for(;;)
    {
      time = libjniOrbitUtils.iccGetTime();
      phiGrn = libjniOrbitUtils.iccGetPhiGrn(time);
      str1 = Long.toString(time);
      str2 = Double.toString(phiGrn);
     
      label1.setText("TIME: " + time);
      label2.setText("PhiGrn: " + str2.substring(0,11));

      try{ Thread.sleep(1000); } catch( InterruptedException ie ) {}
    }

  }

}

//--------------------------------UNCLASSIFIED----------------------------------
