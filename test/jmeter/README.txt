To get these tests to work with your environment:

1. Edit "HTTP Request Defaults"  and change the server name from "parcc-prcc" to your server name
2. In the Workbench, copy the Global settings port, or choose your own.
3. Open Firefox, Go to Preferences > Advanced > Network > Connection Settings.
4. Choose manual proxy, set your servername as above and change your port settings to match Step 2.
5. After making specific changes for tests (see below), click the Green arrow run u

Specific setup for tests:

PRC-472.jmx (Anonymous User browsing the Digital Library)
    1. Devel generate 200 digital library content items, and make sure they have the Subject, Grade Level, and
       Standard fields filled on the ones that you actually view.
    2. Under the Recording Controller, change the URLs for the last two samplers to URLs for digital library content on
       your system

PRC-473.jmx (PARCC-Member Educator DLC viewing and favorites)
    1. If you haven't already, devel generate DL content from step 1 in PRC-472
    2. If it doesn't exist, create the following user in your environment:
        a. Email: member@example.com
        b. Password: qa
        c. Role: PARCC-Member Educator
        e. First name: Peri
        f. Last name: Brown
        g. Check "my state is a PARCC member"
        h. Enter state account number: ILLI1
    3. Under the Recording Controller, change the URLs for the samplers 390, 444, 624 and 798 to URLs for digital
       library content on your system
