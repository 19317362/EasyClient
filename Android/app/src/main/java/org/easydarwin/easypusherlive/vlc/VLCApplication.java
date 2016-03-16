/*****************************************************************************
 * VLCApplication.java
 *****************************************************************************
 * Copyright © 2010-2013 VLC authors and VideoLAN
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
package org.easydarwin.easypusherlive.vlc;

import android.app.Application;
import android.content.Context;
import android.content.res.Resources;

public class VLCApplication extends Application {
    public final static String TAG = "VLC/VLCApplication";
    private static VLCApplication instance;

    @Override
    public void onCreate() {
        super.onCreate();


        instance = this;


    }



    /**
     * @return the main context of the Application
     */
    public static Context getAppContext()
    {
        return instance;
    }

    public static Resources getAppResources()
    {
        return instance.getResources();
    }


}
