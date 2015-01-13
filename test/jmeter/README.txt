To get these tests to work with your environment:

1. Edit "HTTP Request Defaults"  and change the server name from "parcc-prcc" to your server name
2. In the Workbench, copy the Global settings port, or choose your own.
3. Open Firefox, Go to Preferences > Advanced > Network > Connection Settings.
4. Choose manual proxy, set your servername as above and change your port settings to match Step 2.
5. After making specific changes for tests (see below), click the Green arrow run u

Specific setup for tests:

PRC-472.jmx (Anonymous User browsing the Digital Library)
    1. Devel generate 200 digital library content items.
    2. Under the Recording Controller, change the URLs for the last two samplers to URLs for digital library content on
       your system
       
