package org.ieee.jcc.astro;

import org.ieee.jcc.util.DEBUG;

//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: jcc.astro.Jupiter.java
//
// Desc: Ephemeris predictions for Jupiter.
//
// Hist: When       Who  What
//       04/27/2016 ptb  Initial Code.
//------------------------------------------------------------------------------------------------
public class Jupiter extends Planet
{

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public Jupiter()                                                   //
  {                                                                  //
    super();
  }

  //---------------------------------------UNCLASSIFIED-------------------------------------------
  // main
  //----------------------------------------------------------------------------------------------
  public static void main(String[] args)
  {
    Planet Jupiter = new Planet();

    Jupiter.update(1994, 5, 20, 20, 0, 0.0);
    DEBUG.MESSAGEF("Jupiter Pos 19940520:20:00:00\n");
    DEBUG.MESSAGEF("Jupiter Posx = %12.8f\n", Jupiter.R.x);
    DEBUG.MESSAGEF("Jupiter Posy = %12.8f\n", Jupiter.R.y);
    DEBUG.MESSAGEF("Jupiter Posz = %12.8f\n", Jupiter.R.z);
    DEBUG.MESSAGEF("Jupiter Rnge = %12.8f\n", Jupiter.R.mag());

    DEBUG.PRINTF("\n\n\n");

    Jupiter.update(1994, 4, 28, 0, 0, 0.0);
    DEBUG.MESSAGEF("Jupiter Pos 19940428:00:00:00\n");
    DEBUG.MESSAGEF("Jupiter Posx = %12.8f\n", Jupiter.R.x);
    DEBUG.MESSAGEF("Jupiter Posy = %12.8f\n", Jupiter.R.y);
    DEBUG.MESSAGEF("Jupiter Posz = %12.8f\n", Jupiter.R.z);
    DEBUG.MESSAGEF("Jupiter Rnge = %12.8f\n", Jupiter.R.mag());

    DEBUG.PRINTF("\n\n\n");

    Jupiter.update();
    DEBUG.MESSAGEF("Jupiter Pos now.\n");
    DEBUG.MESSAGEF("Jupiter Posx = %12.8f\n", Jupiter.R.x);
    DEBUG.MESSAGEF("Jupiter Posy = %12.8f\n", Jupiter.R.y);
    DEBUG.MESSAGEF("Jupiter Posz = %12.8f\n", Jupiter.R.z);
    DEBUG.MESSAGEF("Jupiter Rnge = %12.8f\n", Jupiter.R.mag());
    DEBUG.MESSAGEF("Jupiter R AU = %12.8f\n", Jupiter.R.mag() * AU2KM);
    DEBUG.MESSAGEF("Jupiter Lat  = %12.8f\n", Jupiter.lat() * RA2DE);
    DEBUG.MESSAGEF("Jupiter Lon  = %12.8f\n", Jupiter.lon() * RA2DE);

    DEBUG.MESSAGEF("Jupiter.Rxyz.strFrmt() is %s\n", Jupiter.R.strFrmt());

    System.out.printf(DEBUG.MESSAGE("DONE\n"));
  }
}