//--------------------------------UNCLASSIFIED----------------------------------
// File: plotPanel.java
// Desc: This file contains the code for the plotPanel class.
// Hist: When       Who  What
//       02/18/2002 ptb  Initial Code.
//--------------------------------UNCLASSIFIED----------------------------------

// Import Files.
// -----------------------------------------------------------------------------
import java.awt.*;
import java.awt.event.*;
import java.lang.*;
import java.io.*;
import java.util.*;
import javax.swing.*;
import javax.swing.event.*;

// Classes.
// -----------------------------------------------------------------------------
class plotPanel extends JPanel {
    Dimension dim;

    public plotPanel() {
	this.setBackground(Color.white);
	dim = getSize();
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g); //paint background

        //Draw line.
	dim = getSize();
        g.drawLine(0,0,dim.width,dim.height);
	//System.out.println(dim.height);
	//System.out.println(dim.width);
    }
}

//--------------------------------UNCLASSIFIED----------------------------------
