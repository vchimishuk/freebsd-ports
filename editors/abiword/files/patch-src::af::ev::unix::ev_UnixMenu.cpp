--- src/af/ev/unix/ev_UnixMenu.cpp.orig	Sat Feb 28 01:01:29 2004
+++ src/af/ev/unix/ev_UnixMenu.cpp	Sat Feb 28 03:05:52 2004
@@ -433,22 +433,20 @@
 	return true;
 }
 
-static char _ev_get_underlined_char(const char * szString)
+static guint _ev_get_underlined_char(const char * szString)
 {
 
 	UT_ASSERT(szString);
 	
-	// return the char right after the underline
-	const char * p = szString;
-	while (*p && *(p+1))
+	// return the keycode right after the underline
+	const UT_UCS4String str(szString);
+	for (int i = 0; i < str.length() - 1; )
 	{
-		if (*p == '_')
-			return *++p;
-		else
-			p++;
+        	if (str[i++] == '_')
+			return gdk_unicode_to_keyval(str[i]);
 	}
 
-	return 0;
+	return GDK_VoidSymbol;
 }
 
 static void _ev_strip_underline(char * bufResult,
@@ -751,12 +749,12 @@
 				// version of the underlined char, since all the menus ignore upper
 				// case (SHIFT-MOD1-[char]) invokations of accelerators.
 
-				if (bAltOnMod1)
+				if (keyCode != GDK_VoidSymbol && bAltOnMod1)
 				{
 					EV_EditEventMapper * pEEM = m_pFrame->getEditEventMapper();
 					UT_ASSERT(pEEM);
 					EV_EditMethod * pEM = NULL;
-					pEEM->Keystroke(EV_EKP_PRESS|EV_EMS_ALT|tolower(keyCode),&pEM);
+					pEEM->Keystroke(EV_EKP_PRESS|EV_EMS_ALT|keyCode,&pEM);
 
 					// if the pointer is valid, there is a conflict
 					bConflict = (pEM != NULL);
