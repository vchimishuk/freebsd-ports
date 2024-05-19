--- lighting.c.orig	2024-05-19 13:09:17 UTC
+++ lighting.c
@@ -25,7 +25,7 @@ Uint32 bgcolor;
 image_type* screen_overlay = NULL;
 Uint32 bgcolor;
 
-const char mask_filename[] = "data/light.png";
+const char mask_filename[] = "%%DATADIR%%/light.png";
 const Uint8 ambient_level = 128;
 
 // Called once at startup.
