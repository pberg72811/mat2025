//--------------------------------UNCLASSIFIED----------------------------------
// File: TestDrive.java
// Desc: This file contains the code for the TestDrive class.
// Hist: When       Who  What
//       09/27/2001 ptb  Initial Code.
//--------------------------------UNCLASSIFIED----------------------------------

// Import Files  ---------------------------------------------------------------
// -----------------------------------------------------------------------------
import java.awt.*;
import java.awt.event.*;
//import java.lang.*;
//import java.io.*;
//import java.util.*;

// TestDrive Class.
// -----------------------------------------------------------------------------
public class TestDrive
{
    public static void main(String args[])
    {
	Button strtButton = new Button("Start");
	Button stopButton = new Button("Stop");
	Button quitButton = new Button("Quit");
        strtButton.addActionListener(new TheActionListener());
        stopButton.addActionListener(new TheActionListener());
        quitButton.addActionListener(new TheActionListener());
	strtButton.setActionCommand("Kowabunga Start");
	stopButton.setActionCommand("Kowabunga Stop");
	quitButton.setActionCommand("Kowabunga Quit");
	System.out.println("Hello from testDrive.");
	Frame theFrame = new Frame("Frame!");
	theFrame.setLayout(new GridLayout(5,1));
	theFrame.setSize(200,300);
	theFrame.setBackground(Color.blue);
        theFrame.add(strtButton);
        theFrame.add(stopButton);
        theFrame.add(quitButton);
	theFrame.setVisible(true);
	theFrame.addWindowListener(new TheFrameListener());
    }
}

// TestWindowListener class.
// -----------------------------------------------------------------------------
class TheFrameListener implements WindowListener
{
    public void windowActivated(WindowEvent e)
    {
	System.out.println("Window Activated");
    }

    public void windowClosed(WindowEvent e)
    {
	System.out.println("Window Closed");
    }

    public void windowClosing(WindowEvent e)
    {
	System.out.println("Window closing");
 	System.exit(0);
    }

    public void windowDeactivated(WindowEvent e)
    {
	System.out.println("Window Deactivated");
    }

    public void windowDeiconified(WindowEvent e)
    {
	System.out.println("Window Deiconified");
    }

    public void windowIconified(WindowEvent e)
    {
	System.out.println("Window Iconified");
    }

    public void windowOpened(WindowEvent e)
    {
	System.out.println("Window Opened");
    }
}

// ... class.
// -----------------------------------------------------------------------------
class  TheActionListener implements ActionListener
{
    public void actionPerformed(ActionEvent e)
    {
	System.out.println("Action event in: " + e.getActionCommand());
    }
}

//--------------------------------UNCLASSIFIED----------------------------------
