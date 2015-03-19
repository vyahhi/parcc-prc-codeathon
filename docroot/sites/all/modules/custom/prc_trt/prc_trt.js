(function ($) {
    Drupal.prc_trt_system_check = {};
    Drupal.behaviors.check_system = {
        attach: function (context) {
            // If this runs, then we have Javascript support
            $('input[name="faux_javascript"]').val(true);
            var has_cookies = are_cookies_enabled();
            $('input[name="faux_cookies"]').val(has_cookies);

            // This will occasionally not return the right value on a first run but always seems to be correct on the second.
            imagesOn = (function () {
                var i = new Image();
                i.setAttribute('onload', "alert('load');window.hasImages = true;");
                i.setAttribute('onerror', "alert('error');window.hasImages = false;");
                //i.src = 'data:text/html,%3C%21doctype%20html%3E%3Chtml%20itemscope%3D""%20itemtype%3D"http%3A%2F%2Fschema.org%2FWebPage"%20lang%3D"en"%3E%3Chead%3E%3Cmeta%20content%3D"Search%20the%20world%27s%20information%2C%20including%20webpages%2C%20images%2C%20videos%20and%20more.%20Google%20has%20many%20special%20features%20to%20help%20you%20find%20exactly%20what%20you%27re%20looking%20for."%20name%3D"description"%3E%3Cmeta%20content%3D"noodp"%20name%3D"robots"%3E%3Cmeta%20content%3D"%2Fimages%2Fgoogle_favicon_128.png"%20itemprop%3D"image"%3E%3Ctitle%3EGoogle%3C%2Ftitle%3E%3Cscript%3E%28function%28%29%7Bwindow.google%3D%7BkEI%3A%27KPUKVdH0LZDtoASky4GQCQ%27%2CkEXPI%3A%2718168%2C3700327%2C3700362%2C3700366%2C4011559%2C4020347%2C4021338%2C4024600%2C4028717%2C4028932%2C4029044%2C4029054%2C4029141%2C4029417%2C4029478%2C4029515%2C4029815%2C4029860%2C4030036%2C4030154%2C4030405%2C4030440%2C4030505%2C4031409%2C4031496%2C4031576%2C4031608%2C8500394%2C8500852%2C8500973%2C10200083%2C10200793%27%2Cauthuser%3A0%2CkSID%3A%27KPUKVdH0LZDtoASky4GQCQ%27%7D%3Bgoogle.kHL%3D%27en%27%3B%7D%29%28%29%3B%28function%28%29%7Bgoogle.lc%3D%5B%5D%3Bgoogle.li%3D0%3Bgoogle.getEI%3Dfunction%28a%29%7Bfor%28var%20b%3Ba%26%26%28%21a.getAttribute%7C%7C%21%28b%3Da.getAttribute%28"eid"%29%29%29%3B%29a%3Da.parentNode%3Breturn%20b%7C%7Cgoogle.kEI%7D%3Bgoogle.getLEI%3Dfunction%28a%29%7Bfor%28var%20b%3Dnull%3Ba%26%26%28%21a.getAttribute%7C%7C%21%28b%3Da.getAttribute%28"leid"%29%29%29%3B%29a%3Da.parentNode%3Breturn%20b%7D%3Bgoogle.https%3Dfunction%28%29%7Breturn"https%3A"%3D%3Dwindow.location.protocol%7D%3Bgoogle.ml%3Dfunction%28%29%7B%7D%3Bgoogle.time%3Dfunction%28%29%7Breturn%28new%20Date%29.getTime%28%29%7D%3Bgoogle.log%3Dfunction%28a%2Cb%2Ce%2Cf%2Cl%29%7Bvar%20d%3Dnew%20Image%2Ch%3Dgoogle.lc%2Cg%3Dgoogle.li%2Cc%3D""%2Cm%3Dgoogle.ls%7C%7C""%3Bd.onerror%3Dd.onload%3Dd.onabort%3Dfunction%28%29%7Bdelete%20h%5Bg%5D%7D%3Bh%5Bg%5D%3Dd%3Bif%28%21e%26%26-1%3D%3Db.search%28"%26ei%3D"%29%29%7Bvar%20k%3Dgoogle.getEI%28f%29%2Cc%3D"%26ei%3D"%2Bk%3B-1%3D%3Db.search%28"%26lei%3D"%29%26%26%28%28f%3Dgoogle.getLEI%28f%29%29%3Fc%2B%3D"%26lei%3D"%2Bf%3Ak%21%3Dgoogle.kEI%26%26%28c%2B%3D"%26lei%3D"%2Bgoogle.kEI%29%29%7Da%3De%7C%7C"%2F"%2B%28l%7C%7C"gen_204"%29%2B"%3Fatyp%3Di%26ct%3D"%2Ba%2B"%26cad%3D"%2Bb%2Bc%2Bm%2B"%26zx%3D"%2Bgoogle.time%28%29%3B%2F%5Ehttp%3A%2Fi.test%28a%29%26%26google.https%28%29%3F%28google.ml%28Error%28"a"%29%2C%211%2C%7Bsrc%3Aa%2Cglmm%3A1%7D%29%2Cdelete%20h%5Bg%5D%29%3A%28d.src%3Da%2Cgoogle.li%3Dg%2B1%29%7D%3Bgoogle.y%3D%7B%7D%3Bgoogle.x%3Dfunction%28a%2Cb%29%7Bgoogle.y%5Ba.id%5D%3D%5Ba%2Cb%5D%3Breturn%211%7D%3Bgoogle.load%3Dfunction%28a%2Cb%2Ce%29%7Bgoogle.x%28%7Bid%3Aa%2Bn%2B%2B%7D%2Cfunction%28%29%7Bgoogle.load%28a%2Cb%2Ce%29%7D%29%7D%3Bvar%20n%3D0%3B%7D%29%28%29%3Bgoogle.kCSI%3D%7B%7D%3Bvar%20_gjwl%3Dlocation%3Bfunction%20_gjuc%28%29%7Bvar%20a%3D_gjwl.href.indexOf%28"%23"%29%3Bif%280%3C%3Da%26%26%28a%3D_gjwl.href.substring%28a%29%2C0%3Ca.indexOf%28"%26q%3D"%29%7C%7C0%3C%3Da.indexOf%28"%23q%3D"%29%29%26%26%28a%3Da.substring%281%29%2C-1%3D%3Da.indexOf%28"%23"%29%29%29%7Bfor%28var%20d%3D0%3Bd%3Ca.length%3B%29%7Bvar%20b%3Dd%3B"%26"%3D%3Da.charAt%28b%29%26%26%2B%2Bb%3Bvar%20c%3Da.indexOf%28"%26"%2Cb%29%3B-1%3D%3Dc%26%26%28c%3Da.length%29%3Bb%3Da.substring%28b%2Cc%29%3Bif%280%3D%3Db.indexOf%28"fp%3D"%29%29a%3Da.substring%280%2Cd%29%2Ba.substring%28c%2Ca.length%29%2Cc%3Dd%3Belse%20if%28"cad%3Dh"%3D%3Db%29return%200%3Bd%3Dc%7D_gjwl.href%3D"%2Fsearch%3F"%2Ba%2B"%26cad%3Dh"%3Breturn%201%7Dreturn%200%7D%0Afunction%20_gjh%28%29%7B%21_gjuc%28%29%26%26window.google%26%26google.x%26%26google.x%28%7Bid%3A"GJH"%7D%2Cfunction%28%29%7Bgoogle.nav%26%26google.nav.gjh%26%26google.nav.gjh%28%29%7D%29%7D%3Bwindow._gjh%26%26_gjh%28%29%3B%3C%2Fscript%3E%3Cstyle%3E%23gbar%2C%23guser%7Bfont-size%3A13px%3Bpadding-top%3A1px%20%21important%3B%7D%23gbar%7Bheight%3A22px%7D%23guser%7Bpadding-bottom%3A7px%20%21important%3Btext-align%3Aright%7D.gbh%2C.gbd%7Bborder-top%3A1px%20solid%20%23c9d7f1%3Bfont-size%3A1px%7D.gbh%7Bheight%3A0%3Bposition%3Aabsolute%3Btop%3A24px%3Bwidth%3A100%25%7D%40media%20all%7B.gb1%7Bheight%3A22px%3Bmargin-right%3A.5em%3Bvertical-align%3Atop%7D%23gbar%7Bfloat%3Aleft%7D%7Da.gb1%2Ca.gb4%7Btext-decoration%3Aunderline%20%21important%7Da.gb1%2Ca.gb4%7Bcolor%3A%2300c%20%21important%7D.gbi%20.gb4%7Bcolor%3A%23dd8e27%20%21important%7D.gbf%20.gb4%7Bcolor%3A%23900%20%21important%7D%3C%2Fstyle%3E%3Cstyle%3Ebody%2Ctd%2Ca%2Cp%2C.h%7Bfont-family%3Aarial%2Csans-serif%7Dbody%7Bmargin%3A0%3Boverflow-y%3Ascroll%7D%23gog%7Bpadding%3A3px%208px%200%7Dtd%7Bline-height%3A.8em%7D.gac_m%20td%7Bline-height%3A17px%7Dform%7Bmargin-bottom%3A20px%7D.h%7Bcolor%3A%2336c%7D.q%7Bcolor%3A%2300c%7D.ts%20td%7Bpadding%3A0%7D.ts%7Bborder-collapse%3Acollapse%7Dem%7Bfont-weight%3Abold%3Bfont-style%3Anormal%7D.lst%7Bheight%3A25px%3Bwidth%3A496px%7D.gsfi%2C.lst%7Bfont%3A18px%20arial%2Csans-serif%7D.gsfs%7Bfont%3A17px%20arial%2Csans-serif%7D.ds%7Bdisplay%3Ainline-box%3Bdisplay%3Ainline-block%3Bmargin%3A3px%200%204px%3Bmargin-left%3A4px%7Dinput%7Bfont-family%3Ainherit%7Da.gb1%2Ca.gb2%2Ca.gb3%2Ca.gb4%7Bcolor%3A%2311c%20%21important%7Dbody%7Bbackground%3A%23fff%3Bcolor%3Ablack%7Da%7Bcolor%3A%2311c%3Btext-decoration%3Anone%7Da%3Ahover%2Ca%3Aactive%7Btext-decoration%3Aunderline%7D.fl%20a%7Bcolor%3A%2336c%7Da%3Avisited%7Bcolor%3A%23551a8b%7Da.gb1%2Ca.gb4%7Btext-decoration%3Aunderline%7Da.gb3%3Ahover%7Btext-decoration%3Anone%7D%23ghead%20a.gb2%3Ahover%7Bcolor%3A%23fff%20%21important%7D.sblc%7Bpadding-top%3A5px%7D.sblc%20a%7Bdisplay%3Ablock%3Bmargin%3A2px%200%3Bmargin-left%3A13px%3Bfont-size%3A11px%7D.lsbb%7Bbackground%3A%23eee%3Bborder%3Asolid%201px%3Bborder-color%3A%23ccc%20%23999%20%23999%20%23ccc%3Bheight%3A30px%7D.lsbb%7Bdisplay%3Ablock%7D.ftl%2C%23fll%20a%7Bdisplay%3Ainline-block%3Bmargin%3A0%2012px%7D.lsb%7Bbackground%3Aurl%28%2Fimages%2Fsrpr%2Fnav_logo80.png%29%200%20-258px%20repeat-x%3Bborder%3Anone%3Bcolor%3A%23000%3Bcursor%3Apointer%3Bheight%3A30px%3Bmargin%3A0%3Boutline%3A0%3Bfont%3A15px%20arial%2Csans-serif%3Bvertical-align%3Atop%7D.lsb%3Aactive%7Bbackground%3A%23ccc%7D.lst%3Afocus%7Boutline%3Anone%7D%3C%2Fstyle%3E%3Cscript%3E%3C%2Fscript%3E%3C%2Fhead%3E%3Cbody%20bgcolor%3D"%23fff"%3E%3Cscript%3E%28function%28%29%7Bvar%20src%3D%27%2Fimages%2Fnav_logo176.png%27%3Bvar%20iesg%3Dfalse%3Bdocument.body.onload%20%3D%20function%28%29%7Bwindow.n%20%26%26%20window.n%28%29%3Bif%20%28document.images%29%7Bnew%20Image%28%29.src%3Dsrc%3B%7D%0Aif%20%28%21iesg%29%7Bdocument.f%26%26document.f.q.focus%28%29%3Bdocument.gbqf%26%26document.gbqf.q.focus%28%29%3B%7D%0A%7D%0A%7D%29%28%29%3B%3C%2Fscript%3E%3Cdiv%20id%3D"mngb"%3E%20%20%20%20%3Cdiv%20id%3Dgbar%3E%3Cnobr%3E%3Cb%20class%3Dgb1%3ESearch%3C%2Fb%3E%20%3Ca%20class%3Dgb1%20href%3D"http%3A%2F%2Fwww.google.com%2Fimghp%3Fhl%3Den%26tab%3Dwi"%3EImages%3C%2Fa%3E%20%3Ca%20class%3Dgb1%20href%3D"http%3A%2F%2Fmaps.google.com%2Fmaps%3Fhl%3Den%26tab%3Dwl"%3EMaps%3C%2Fa%3E%20%3Ca%20class%3Dgb1%20href%3D"https%3A%2F%2Fplay.google.com%2F%3Fhl%3Den%26tab%3Dw8"%3EPlay%3C%2Fa%3E%20%3Ca%20class%3Dgb1%20href%3D"http%3A%2F%2Fwww.youtube.com%2F%3Ftab%3Dw1"%3EYouTube%3C%2Fa%3E%20%3Ca%20class%3Dgb1%20href%3D"http%3A%2F%2Fnews.google.com%2Fnwshp%3Fhl%3Den%26tab%3Dwn"%3ENews%3C%2Fa%3E%20%3Ca%20class%3Dgb1%20href%3D"https%3A%2F%2Fmail.google.com%2Fmail%2F%3Ftab%3Dwm"%3EGmail%3C%2Fa%3E%20%3Ca%20class%3Dgb1%20href%3D"https%3A%2F%2Fdrive.google.com%2F%3Ftab%3Dwo"%3EDrive%3C%2Fa%3E%20%3Ca%20class%3Dgb1%20style%3D"text-decoration%3Anone"%20href%3D"http%3A%2F%2Fwww.google.com%2Fintl%2Fen%2Foptions%2F"%3E%3Cu%3EMore%3C%2Fu%3E%20%26raquo%3B%3C%2Fa%3E%3C%2Fnobr%3E%3C%2Fdiv%3E%3Cdiv%20id%3Dguser%20width%3D100%25%3E%3Cnobr%3E%3Cspan%20id%3Dgbn%20class%3Dgbi%3E%3C%2Fspan%3E%3Cspan%20id%3Dgbf%20class%3Dgbf%3E%3C%2Fspan%3E%3Cspan%20id%3Dgbe%3E%3C%2Fspan%3E%3Ca%20href%3D"http%3A%2F%2Fwww.google.com%2Fhistory%2Foptout%3Fhl%3Den"%20class%3Dgb4%3EWeb%20History%3C%2Fa%3E%20%7C%20%3Ca%20%20href%3D"%2Fpreferences%3Fhl%3Den"%20class%3Dgb4%3ESettings%3C%2Fa%3E%20%7C%20%3Ca%20target%3D_top%20id%3Dgb_70%20href%3D"https%3A%2F%2Faccounts.google.com%2FServiceLogin%3Fhl%3Den%26continue%3Dhttp%3A%2F%2Fwww.google.com%2F"%20class%3Dgb4%3ESign%20in%3C%2Fa%3E%3C%2Fnobr%3E%3C%2Fdiv%3E%3Cdiv%20class%3Dgbh%20style%3Dleft%3A0%3E%3C%2Fdiv%3E%3Cdiv%20class%3Dgbh%20style%3Dright%3A0%3E%3C%2Fdiv%3E%20%20%20%20%3C%2Fdiv%3E%3Ccenter%3E%3Cspan%20id%3D"prt"%20style%3D"display%3Ablock"%3E%20%3Cdiv%3E%3Cstyle%3E.pmoabs%7Bbackground-color%3A%23fff%3Bborder%3A1px%20solid%20%23E5E5E5%3Bcolor%3A%23666%3Bfont-size%3A13px%3Bpadding-bottom%3A20px%3Bposition%3Aabsolute%3Bright%3A2px%3Btop%3A3px%3Bz-index%3A986%7D%23pmolnk%7Bborder-radius%3A2px%3B-moz-border-radius%3A2px%3B-webkit-border-radius%3A2px%7D.kd-button-submit%7Bborder%3A1px%20solid%20%233079ed%3Bbackground-color%3A%234d90fe%3Bbackground-image%3A-webkit-gradient%28linear%2Cleft%20top%2Cleft%20bottom%2Cfrom%28%234d90fe%29%2Cto%28%234787ed%29%29%3Bbackground-image%3A-webkit-linear-gradient%28top%2C%234d90fe%2C%234787ed%29%3Bbackground-image%3A-moz-linear-gradient%28top%2C%234d90fe%2C%234787ed%29%3Bbackground-image%3A-ms-linear-gradient%28top%2C%234d90fe%2C%234787ed%29%3Bbackground-image%3A-o-linear-gradient%28top%2C%234d90fe%2C%234787ed%29%3Bbackground-image%3Alinear-gradient%28top%2C%234d90fe%2C%234787ed%29%3Bfilter%3Aprogid%3ADXImageTransform.Microsoft.gradient%28startColorStr%3D%27%234d90fe%27%2CEndColorStr%3D%27%234787ed%27%29%7D.kd-button-submit%3Ahover%7Bborder%3A1px%20solid%20%232f5bb7%3Bbackground-color%3A%23357ae8%3Bbackground-image%3A-webkit-gradient%28linear%2Cleft%20top%2Cleft%20bottom%2Cfrom%28%234d90fe%29%2Cto%28%23357ae8%29%29%3Bbackground-image%3A-webkit-linear-gradient%28top%2C%234d90fe%2C%23357ae8%29%3Bbackground-image%3A-moz-linear-gradient%28top%2C%234d90fe%2C%23357ae8%29%3Bbackground-image%3A-ms-linear-gradient%28top%2C%234d90fe%2C%23357ae8%29%3Bbackground-image%3A-o-linear-gradient%28top%2C%234d90fe%2C%23357ae8%29%3Bbackground-image%3Alinear-gradient%28top%2C%234d90fe%2C%23357ae8%29%3Bfilter%3Aprogid%3ADXImageTransform.Microsoft.gradient%28startColorStr%3D%27%234d90fe%27%2CEndColorStr%3D%27%23357ae8%27%29%7D.kd-button-submit%3Aactive%7B-webkit-box-shadow%3Ainset%200%201px%202px%20rgba%280%2C0%2C0%2C0.3%29%3B-moz-box-shadow%3Ainset%200%201px%202px%20rgba%280%2C0%2C0%2C0.3%29%3Bbox-shadow%3Ainset%200%201px%202px%20rgba%280%2C0%2C0%2C0.3%29%7D%23pmolnk%20a%7Bcolor%3A%23fff%3Bdisplay%3Ainline-block%3Bfont-weight%3Abold%3Bpadding%3A5px%2020px%3Btext-decoration%3Anone%3Bwhite-space%3Anowrap%7D.xbtn%7Bcolor%3A%23999%3Bcursor%3Apointer%3Bfont-size%3A23px%3Bline-height%3A5px%3Bpadding-top%3A5px%7D.padi%7Bpadding%3A0%208px%200%2010px%7D.padt%7Bpadding%3A5px%2020px%200%200%3Bcolor%3A%23444%7D.pads%7Btext-align%3Aleft%3Bmax-width%3A200px%7D%3C%2Fstyle%3E%20%3Cdiv%20class%3D"pmoabs"%20id%3D"pmocntr2"%20style%3D"behavior%3Aurl%28%23default%23userdata%29%3Bdisplay%3Anone"%3E%20%3Ctable%20border%3D"0"%3E%20%3Ctr%3E%20%3Ctd%20colspan%3D"2"%3E%20%3Cdiv%20class%3D"xbtn"%20onclick%3D"google.promos%26%26google.promos.toast%26%26%20google.promos.toast.cpc%28%29"%20style%3D"float%3Aright"%3E%26times%3B%3C%2Fdiv%3E%20%3C%2Ftd%3E%20%3C%2Ftr%3E%20%3Ctr%3E%20%3Ctd%20class%3D"padi"%20rowspan%3D"2"%3E%20%3Cimg%20src%3D"%2Fimages%2Ficons%2Fproduct%2Fchrome-48.png"%3E%20%3C%2Ftd%3E%20%3Ctd%20class%3D"pads"%3EA%20faster%20way%20to%20browse%20the%20web%3C%2Ftd%3E%20%3C%2Ftr%3E%20%3Ctr%3E%20%3Ctd%20class%3D"padt"%3E%20%3Cdiv%20class%3D"kd-button-submit"%20id%3D"pmolnk"%3E%20%3Ca%20href%3D"%2Fchrome%2Findex.html%3Fhl%3Den%26amp%3Bbrand%3DCHNG%26amp%3Butm_source%3Den-hpp%26amp%3Butm_medium%3Dhpp%26amp%3Butm_campaign%3Den"%20onclick%3D"google.promos%26%26google.promos.toast%26%26%20google.promos.toast.cl%28%29"%3EInstall%20Google%20Chrome%3C%2Fa%3E%20%3C%2Fdiv%3E%20%3C%2Ftd%3E%20%3C%2Ftr%3E%20%3C%2Ftable%3E%20%3C%2Fdiv%3E%20%3Cscript%20type%3D"text%2Fjavascript"%3E%28function%28%29%7Bvar%20a%3D%7Bo%3A%7B%7D%7D%3Ba.o.qa%3D50%3Ba.o.oa%3D10%3Ba.o.Y%3D"body"%3Ba.o.Oa%3D%210%3Ba.o.Ra%3Dfunction%28b%2Cc%29%7Bvar%20d%3Da.o.Ea%28%29%3Ba.o.Ga%28d%2Cb%2Cc%29%3Ba.o.Sa%28d%29%3Ba.o.Oa%26%26a.o.Pa%28d%29%7D%3Ba.o.Sa%3Dfunction%28b%29%7B%28b%3Da.o.%24%28b%29%29%26%260%3Cb.forms.length%26%26b.forms%5B0%5D.submit%28%29%7D%3Ba.o.Ea%3Dfunction%28%29%7Bvar%20b%3Ddocument.createElement%28"iframe"%29%3Bb.height%3D0%3Bb.width%3D0%3Bb.style.overflow%3D"hidden"%3Bb.style.top%3Db.style.left%3D"-100px"%3Bb.style.position%3D"absolute"%3Bdocument.body.appendChild%28b%29%3Breturn%20b%7D%3Ba.o.%24%3Dfunction%28b%29%7Breturn%20b.contentDocument%7C%7Cb.contentWindow.document%7D%3Ba.o.Ga%3Dfunction%28b%2Cc%2Cd%29%7Bb%3Da.o.%24%28b%29%3Bb.open%28%29%3Bd%3D%5B"%3C"%2Ca.o.Y%2C%27%3E%3Cform%20method%3DPOST%20action%3D"%27%2Cd%2C%27"%3E%27%5D%3Bfor%28var%20e%20in%20c%29c.hasOwnProperty%28e%29%26%26d.push%28%27%3Ctextarea%20name%3D"%27%2Ce%2C%27"%3E%27%2Cc%5Be%5D%2C"%3C%2Ftextarea%3E"%29%3Bd.push%28"%3C%2Fform%3E%3C%2F"%2Ca.o.Y%2C"%3E"%29%3Bb.write%28d.join%28""%29%29%3Bb.close%28%29%7D%3Ba.o.ba%3Dfunction%28b%2Cc%29%7Bc%3Ea.o.oa%3Fgoogle%26%26google.ml%26%26google.ml%28Error%28"ogcdr"%29%2C%211%2C%7Bcause%3A"timeout"%7D%29%3Ab.contentWindow%3Fa.o.Qa%28b%29%3Awindow.setTimeout%28function%28%29%7Ba.o.ba%28b%2Cc%2B1%29%7D%2Ca.o.qa%29%7D%3Ba.o.Qa%3Dfunction%28b%29%7Bdocument.body.removeChild%28b%29%7D%3Ba.o.Pa%3Dfunction%28b%29%7Ba.o.Ca%28b%2C"load"%2Cfunction%28%29%7Ba.o.ba%28b%2C0%29%7D%29%7D%3Ba.o.Ca%3Dfunction%28b%2Cc%2Cd%29%7Bb.addEventListener%3Fb.addEventListener%28c%2Cd%2C%211%29%3Ab.attachEvent%26%26b.attachEvent%28"on"%2Bc%2Cd%29%7D%3Bvar%20m%3D%7BVa%3A0%2CD%3A1%2CF%3A2%2CK%3A5%7D%3Ba.k%3D%7B%7D%3Ba.k.M%3D%7Bka%3A"i"%2CJ%3A"d"%2Cma%3A"l"%7D%3Ba.k.A%3D%7BN%3A"0"%2CG%3A"1"%7D%3Ba.k.O%3D%7BL%3A1%2CJ%3A2%2CI%3A3%7D%3Ba.k.v%3D%7Bea%3A"a"%2Cia%3A"g"%2CC%3A"c"%2Cya%3A"u"%2Cxa%3A"t"%2CN%3A"p"%2Cpa%3A"pid"%2Cga%3A"eid"%2Cza%3A"at"%7D%3Ba.k.la%3Dwindow.location.protocol%2B"%2F%2Fwww.google.com%2F_%2Fog%2Fpromos%2F"%3Ba.k.ha%3D"g"%3Ba.k.Aa%3D"z"%3Ba.k.S%3Dfunction%28b%2Cc%2Cd%2Ce%29%7Bvar%20f%3Dnull%3Bswitch%28c%29%7Bcase%20m.D%3Af%3Dwindow.gbar.up.gpd%28b%2Cd%2C%210%29%3Bbreak%3Bcase%20m.K%3Af%3Dwindow.gbar.up.gcc%28e%29%7Dreturn%20null%3D%3Df%3F0%3AparseInt%28f%2C10%29%7D%3Ba.k.Ka%3Dfunction%28b%2Cc%2Cd%29%7Breturn%20c%3D%3Dm.D%3Fnull%21%3Dwindow.gbar.up.gpd%28b%2Cd%2C%210%29%3A%211%7D%3Ba.k.P%3Dfunction%28b%2Cc%2Cd%2Ce%2Cf%2Ch%2Ck%2Cl%29%7Bvar%20g%3D%7B%7D%3Bg%5Ba.k.v.N%5D%3Db%3Bg%5Ba.k.v.ia%5D%3Dc%3Bg%5Ba.k.v.ea%5D%3Dd%3Bg%5Ba.k.v.za%5D%3De%3Bg%5Ba.k.v.ga%5D%3Df%3Bg%5Ba.k.v.pa%5D%3D1%3Bk%26%26%28g%5Ba.k.v.C%5D%3Dk%29%3Bl%26%26%28g%5Ba.k.v.ya%5D%3Dl%29%3Bif%28h%29g%5Ba.k.v.xa%5D%3Dh%3Belse%20return%20google.ml%28Error%28"knu"%29%2C%211%2C%7Bcause%3A"Token%20is%20not%20found"%7D%29%2Cnull%3Breturn%20g%7D%3Ba.k.V%3Dfunction%28b%2Cc%2Cd%29%7Bif%28b%29%7Bvar%20e%3Dc%3Fa.k.ha%3Aa.k.Aa%3Bc%26%26d%26%26%28e%2B%3D"%3Fauthuser%3D"%2Bd%29%3Ba.o.Ra%28b%2Ca.k.la%2Be%29%7D%7D%3Ba.k.Fa%3Dfunction%28b%2Cc%2Cd%2Ce%2Cf%2Ch%2Ck%29%7Bb%3Da.k.P%28c%2Cb%2Ca.k.M.J%2Ca.k.O.J%2Cd%2Cf%2Cnull%2Ce%29%3Ba.k.V%28b%2Ch%2Ck%29%7D%3Ba.k.Ia%3Dfunction%28b%2Cc%2Cd%2Ce%2Cf%2Ch%2Ck%29%7Bb%3Da.k.P%28c%2Cb%2Ca.k.M.ka%2Ca.k.O.L%2Cd%2Cf%2Ce%2Cnull%29%3Ba.k.V%28b%2Ch%2Ck%29%7D%3Ba.k.Na%3Dfunction%28b%2Cc%2Cd%2Ce%2Cf%2Ch%2Ck%2Cl%2Cg%2Cn%29%7Bswitch%28c%29%7Bcase%20m.K%3Awindow.gbar.up.dpc%28e%2Cf%29%3Bbreak%3Bcase%20m.D%3Awindow.gbar.up.spd%28b%2Cd%2C1%2C%210%29%3Bbreak%3Bcase%20m.F%3Ag%3Dg%7C%7C%211%2Cl%3Dl%7C%7C""%2Ch%3Dh%7C%7C0%2Ck%3Dk%7C%7Ca.k.A.G%2Cn%3Dn%7C%7C0%2Ca.k.Fa%28e%2Ch%2Ck%2Cf%2Cl%2Cg%2Cn%29%7D%7D%3Ba.k.La%3Dfunction%28b%2Cc%2Cd%2Ce%2Cf%29%7Breturn%20c%3D%3Dm.D%3F0%3Cd%26%26a.k.S%28b%2Cc%2Ce%2Cf%29%3E%3Dd%3A%211%7D%3Ba.k.Ha%3Dfunction%28b%2Cc%2Cd%2Ce%2Cf%2Ch%2Ck%2Cl%2Cg%2Cn%29%7Bswitch%28c%29%7Bcase%20m.K%3Awindow.gbar.up.iic%28e%2Cf%29%3Bbreak%3Bcase%20m.D%3Ac%3Da.k.S%28b%2Cc%2Cd%2Ce%29%2B1%3Bwindow.gbar.up.spd%28b%2Cd%2Cc.toString%28%29%2C%210%29%3Bbreak%3Bcase%20m.F%3Ag%3Dg%7C%7C%211%2Cl%3Dl%7C%7C""%2Ch%3Dh%7C%7C0%2Ck%3Dk%7C%7Ca.k.A.N%2Cn%3Dn%7C%7C0%2Ca.k.Ia%28e%2Ch%2Ck%2C1%2Cl%2Cg%2Cn%29%7D%7D%3Ba.k.Ma%3Dfunction%28b%2Cc%2Cd%2Ce%2Cf%2Ch%29%7Bb%3Da.k.P%28c%2Cb%2Ca.k.M.ma%2Ca.k.O.I%2Cd%2Ce%2Cnull%2Cnull%29%3Ba.k.V%28b%2Cf%2Ch%29%7D%3Bvar%20p%3D%7BTa%3A"a"%2CWa%3A"l"%2CUa%3A"c"%2Cfa%3A"d"%2CI%3A"h"%2CL%3A"i"%2Cgb%3A"n"%2CG%3A"x"%2Ccb%3A"ma"%2Ceb%3A"mc"%2Cfb%3A"mi"%2CXa%3A"pa"%2CYa%3A"pc"%2C%24a%3A"pi"%2Cbb%3A"pn"%2Cab%3A"px"%2CZa%3A"pd"%2Chb%3A"gpa"%2Cjb%3A"gpi"%2Ckb%3A"gpn"%2Clb%3A"gpx"%2Cib%3A"gpd"%7D%3Ba.i%3D%7B%7D%3Ba.i.s%3D%7Bna%3A"hplogo"%2Cwa%3A"pmocntr2"%7D%3Ba.i.A%3D%7Bva%3A"0"%2CG%3A"1"%2Cda%3A"2"%7D%3Ba.i.p%3Ddocument.getElementById%28a.i.s.wa%29%3Ba.i.ja%3D16%3Ba.i.ra%3D2%3Ba.i.ta%3D20%3Bgoogle.promos%3Dgoogle.promos%7C%7C%7B%7D%3Bgoogle.promos.toast%3Dgoogle.promos.toast%7C%7C%7B%7D%3Ba.i.H%3Dfunction%28b%29%7Ba.i.p%26%26%28a.i.p.style.display%3Db%3F""%3A"none"%2Ca.i.p.parentNode%26%26%28a.i.p.parentNode.style.position%3Db%3F"relative"%3A""%29%29%7D%3Ba.i.ca%3Dfunction%28b%29%7Btry%7Bif%28a.i.p%26%26b%26%26b.es%26%26b.es.m%29%7Bvar%20c%3Dwindow.gbar.rtl%28document.body%29%3F"left"%3A"right"%3Ba.i.p.style%5Bc%5D%3Db.es.m-a.i.ja%2Ba.i.ra%2B"px"%3Ba.i.p.style.top%3Da.i.ta%2B"px"%7D%7Dcatch%28d%29%7Bgoogle.ml%28d%2C%211%2C%7Bcause%3Aa.i.w%2B"_PT"%7D%29%7D%7D%3Bgoogle.promos.toast.cl%3Dfunction%28%29%7Btry%7Ba.i.Q%3D%3Dm.F%26%26a.k.Ma%28a.i.T%2Ca.i.B%2Ca.i.A.da%2Ca.i.X%2Ca.i.U%2Ca.i.W%29%2Cwindow.gbar.up.sl%28a.i.B%2Ca.i.w%2Cp.I%2Ca.i.R%28%29%2C1%29%7Dcatch%28b%29%7Bgoogle.ml%28b%2C%211%2C%7Bcause%3Aa.i.w%2B"_CL"%7D%29%7D%7D%3Bgoogle.promos.toast.cpc%3Dfunction%28%29%7Btry%7Ba.i.p%26%26%28a.i.H%28%211%29%2Ca.k.Na%28a.i.p%2Ca.i.Q%2Ca.i.s.Z%2Ca.i.T%2Ca.i.Da%2Ca.i.B%2Ca.i.A.G%2Ca.i.X%2Ca.i.U%2Ca.i.W%29%2Cwindow.gbar.up.sl%28a.i.B%2Ca.i.w%2Cp.fa%2Ca.i.R%28%29%2C1%29%29%7Dcatch%28b%29%7Bgoogle.ml%28b%2C%211%2C%7Bcause%3Aa.i.w%2B"_CPC"%7D%29%7D%7D%3Ba.i.aa%3Dfunction%28%29%7Btry%7Bif%28a.i.p%29%7Bvar%20b%3D276%2Cc%3Ddocument.getElementById%28a.i.s.na%29%3Bc%26%26%28b%3DMath.max%28b%2Cc.offsetWidth%29%29%3Bvar%20d%3DparseInt%28a.i.p.style.right%2C10%29%7C%7C0%3Ba.i.p.style.visibility%3D2%2A%28a.i.p.offsetWidth%2Bd%29%2Bb%3Edocument.body.clientWidth%3F"hidden"%3A""%7D%7Dcatch%28e%29%7Bgoogle.ml%28e%2C%211%2C%7Bcause%3Aa.i.w%2B"_HOSW"%7D%29%7D%7D%3Ba.i.Ba%3Dfunction%28%29%7Bvar%20b%3D%5B"gpd"%2C"spd"%2C"aeh"%2C"sl"%5D%3Bif%28%21window.gbar%7C%7C%21window.gbar.up%29return%211%3Bfor%28var%20c%3D0%2Cd%3Bd%3Db%5Bc%5D%3Bc%2B%2B%29if%28%21%28d%20in%20window.gbar.up%29%29return%211%3Breturn%210%7D%3Ba.i.Ja%3Dfunction%28%29%7Breturn%20a.i.p.currentStyle%26%26"absolute"%21%3Da.i.p.currentStyle.position%7D%3Bgoogle.promos.toast.init%3Dfunction%28b%2Cc%2Cd%2Ce%2Cf%2Ch%2Ck%2Cl%2Cg%2Cn%2Cq%2Cr%29%7Btry%7Ba.i.Ba%28%29%3Fa.i.p%26%26%28e%3D%3Dm.F%26%26%21l%3D%3D%21g%3F%28google.ml%28Error%28"tku"%29%2C%211%2C%7Bcause%3A"zwieback%3A%20"%2Bg%2B"%2C%20gaia%3A%20"%2Bl%7D%29%2Ca.i.H%28%211%29%29%3A%28a.i.s.C%3D"toast_count_"%2Bc%2B%28q%3F"_"%2Bq%3A""%29%2Ca.i.s.Z%3D"toast_dp_"%2Bc%2B%28r%3F"_"%2Br%3A""%29%2Ca.i.w%3Dd%2Ca.i.B%3Db%2Ca.i.Q%3De%2Ca.i.T%3Dc%2Ca.i.Da%3Df%2Ca.i.X%3Dl%3Fl%3Ag%2Ca.i.U%3D%21%21l%2Ca.i.W%3Dk%2Ca.k.Ka%28a.i.p%2Ce%2Ca.i.s.Z%2Cc%29%7C%7Ca.k.La%28a.i.p%2Ce%2Ch%2Ca.i.s.C%2Cc%29%7C%7Ca.i.Ja%28%29%3Fa.i.H%28%211%29%3A%28a.k.Ha%28a.i.p%2Ce%2Ca.i.s.C%2Cc%2Cf%2Ca.i.B%2Ca.i.A.va%2Ca.i.X%2Ca.i.U%2Ca.i.W%29%2Cn%7C%7C%28window.gbar.up.aeh%28window%2C"resize"%2Ca.i.aa%29%2Cwindow.lol%3D%0Aa.i.aa%2Cwindow.gbar.elr%26%26a.i.ca%28window.gbar.elr%28%29%29%2Cwindow.gbar.elc%26%26window.gbar.elc%28a.i.ca%29%2Ca.i.H%28%210%29%29%2Cwindow.gbar.up.sl%28a.i.B%2Ca.i.w%2Cp.L%2Ca.i.R%28%29%29%29%29%29%3Agoogle.ml%28Error%28"apa"%29%2C%211%2C%7Bcause%3Aa.i.w%2B"_INIT"%7D%29%7Dcatch%28t%29%7Bgoogle.ml%28t%2C%211%2C%7Bcause%3Aa.i.w%2B"_INIT"%7D%29%7D%7D%3Ba.i.R%3Dfunction%28%29%7Bvar%20b%3Da.k.S%28a.i.p%2Ca.i.Q%2Ca.i.s.C%2Ca.i.T%29%3Breturn"ic%3D"%2Bb%7D%3B%7D%29%28%29%3B%3C%2Fscript%3E%20%3Cscript%20type%3D"text%2Fjavascript"%3E%28function%28%29%7Bvar%20sourceWebappPromoID%3D144002%3Bvar%20sourceWebappGroupID%3D5%3Bvar%20payloadType%3D5%3Bvar%20cookieMaxAgeSec%3D2592000%3Bvar%20dismissalType%3D5%3Bvar%20impressionCap%3D25%3Bvar%20gaiaXsrfToken%3D%27%27%3Bvar%20zwbkXsrfToken%3D%27%27%3Bvar%20kansasDismissalEnabled%3Dfalse%3Bvar%20sessionIndex%3D0%3Bvar%20invisible%3Dfalse%3Bwindow.gbar%26%26gbar.up%26%26gbar.up.r%26%26gbar.up.r%28payloadType%2Cfunction%28show%29%7Bif%20%28show%29%7Bgoogle.promos.toast.init%28sourceWebappPromoID%2CsourceWebappGroupID%2CpayloadType%2CdismissalType%2CcookieMaxAgeSec%2CimpressionCap%2CsessionIndex%2CgaiaXsrfToken%2CzwbkXsrfToken%2Cinvisible%2C%270612%27%29%3B%7D%0A%7D%29%3B%7D%29%28%29%3B%3C%2Fscript%3E%20%3C%2Fdiv%3E%20%3C%2Fspan%3E%3Cbr%20clear%3D"all"%20id%3D"lgpd"%3E%3Cdiv%20id%3D"lga"%3E%3Cimg%20alt%3D"Google"%20height%3D"95"%20src%3D"%2Fimages%2Fsrpr%2Flogo9w.png"%20style%3D"padding%3A28px%200%2014px"%20width%3D"269"%20id%3D"hplogo"%20onload%3D"window.lol%26%26lol%28%29"%3E%3Cbr%3E%3Cbr%3E%3C%2Fdiv%3E%3Cform%20action%3D"%2Fsearch"%20name%3D"f"%3E%3Ctable%20cellpadding%3D"0"%20cellspacing%3D"0"%3E%3Ctr%20valign%3D"top"%3E%3Ctd%20width%3D"25%25"%3E%26nbsp%3B%3C%2Ftd%3E%3Ctd%20align%3D"center"%20nowrap%3D""%3E%3Cinput%20name%3D"ie"%20value%3D"ISO-8859-1"%20type%3D"hidden"%3E%3Cinput%20value%3D"en"%20name%3D"hl"%20type%3D"hidden"%3E%3Cinput%20name%3D"source"%20type%3D"hidden"%20value%3D"hp"%3E%3Cdiv%20class%3D"ds"%20style%3D"height%3A32px%3Bmargin%3A4px%200"%3E%3Cinput%20style%3D"color%3A%23000%3Bmargin%3A0%3Bpadding%3A5px%208px%200%206px%3Bvertical-align%3Atop"%20autocomplete%3D"off"%20class%3D"lst"%20value%3D""%20title%3D"Google%20Search"%20maxlength%3D"2048"%20name%3D"q"%20size%3D"57"%3E%3C%2Fdiv%3E%3Cbr%20style%3D"line-height%3A0"%3E%3Cspan%20class%3D"ds"%3E%3Cspan%20class%3D"lsbb"%3E%3Cinput%20class%3D"lsb"%20value%3D"Google%20Search"%20name%3D"btnG"%20type%3D"submit"%3E%3C%2Fspan%3E%3C%2Fspan%3E%3Cspan%20class%3D"ds"%3E%3Cspan%20class%3D"lsbb"%3E%3Cinput%20class%3D"lsb"%20value%3D"I%27m%20Feeling%20Lucky"%20name%3D"btnI"%20onclick%3D"if%28this.form.q.value%29this.checked%3D1%3B%20else%20top.location%3D%27%2Fdoodles%2F%27"%20type%3D"submit"%3E%3C%2Fspan%3E%3C%2Fspan%3E%3C%2Ftd%3E%3Ctd%20class%3D"fl%20sblc"%20align%3D"left"%20nowrap%3D""%20width%3D"25%25"%3E%3Ca%20href%3D"%2Fadvanced_search%3Fhl%3Den%26amp%3Bauthuser%3D0"%3EAdvanced%20search%3C%2Fa%3E%3Ca%20href%3D"%2Flanguage_tools%3Fhl%3Den%26amp%3Bauthuser%3D0"%3ELanguage%20tools%3C%2Fa%3E%3C%2Ftd%3E%3C%2Ftr%3E%3C%2Ftable%3E%3Cinput%20id%3D"gbv"%20name%3D"gbv"%20type%3D"hidden"%20value%3D"1"%3E%3C%2Fform%3E%3Cdiv%20id%3D"gac_scont"%3E%3C%2Fdiv%3E%3Cdiv%20style%3D"font-size%3A83%25%3Bmin-height%3A3.5em"%3E%3Cbr%3E%3C%2Fdiv%3E%3Cspan%20id%3D"footer"%3E%3Cdiv%20style%3D"font-size%3A10pt"%3E%3Cdiv%20style%3D"margin%3A19px%20auto%3Btext-align%3Acenter"%20id%3D"fll"%3E%3Ca%20href%3D"%2Fintl%2Fen%2Fads%2F"%3EAdvertising%26nbsp%3BPrograms%3C%2Fa%3E%3Ca%20href%3D"%2Fservices%2F"%3EBusiness%20Solutions%3C%2Fa%3E%3Ca%20href%3D"https%3A%2F%2Fplus.google.com%2F116899029375914044550"%20rel%3D"publisher"%3E%2BGoogle%3C%2Fa%3E%3Ca%20href%3D"%2Fintl%2Fen%2Fabout.html"%3EAbout%20Google%3C%2Fa%3E%3C%2Fdiv%3E%3C%2Fdiv%3E%3Cp%20style%3D"color%3A%23767676%3Bfont-size%3A8pt"%3E%26copy%3B%202015%20-%20%3Ca%20href%3D"%2Fintl%2Fen%2Fpolicies%2Fprivacy%2F"%3EPrivacy%3C%2Fa%3E%20-%20%3Ca%20href%3D"%2Fintl%2Fen%2Fpolicies%2Fterms%2F"%3ETerms%3C%2Fa%3E%3C%2Fp%3E%3C%2Fspan%3E%3C%2Fcenter%3E%3Cdiv%20id%3D"xjsd"%3E%3C%2Fdiv%3E%3Cdiv%20id%3D"xjsi"%20data-jiis%3D"bp"%3E%3Cscript%3E%28function%28%29%7Bfunction%20c%28b%29%7Bwindow.setTimeout%28function%28%29%7Bvar%20a%3Ddocument.createElement%28"script"%29%3Ba.src%3Db%3Bdocument.getElementById%28"xjsd"%29.appendChild%28a%29%7D%2C0%29%7Dgoogle.dljp%3Dfunction%28b%2Ca%29%7Bgoogle.xjsu%3Db%3Bc%28a%29%7D%3Bgoogle.dlj%3Dc%3B%7D%29%28%29%3B%28function%28%29%7Bwindow.google.xjsrm%3D%5B%5D%3B%7D%29%28%29%3Bif%28google.y%29google.y.first%3D%5B%5D%3Bif%28%21google.xjs%29%7Bwindow._%3Dwindow._%7C%7C%7B%7D%3Bwindow._._DumpException%3Dfunction%28e%29%7Bthrow%20e%7D%3Bif%28google.timers%26%26google.timers.load.t%29%7Bgoogle.timers.load.t.xjsls%3Dnew%20Date%28%29.getTime%28%29%3B%7Dgoogle.dljp%28%27%2Fxjs%2F_%2Fjs%2Fk%5Cx3dxjs.hp.en_US.votPZMqb6rk.O%2Fm%5Cx3dsb_he%2Cd%2Frt%5Cx3dj%2Fd%5Cx3d1%2Ft%5Cx3dzcms%2Frs%5Cx3dACT90oGWU4duK4Q5aR8xKQcV-eqzv5iDFw%27%2C%27%2Fxjs%2F_%2Fjs%2Fk%5Cx3dxjs.hp.en_US.votPZMqb6rk.O%2Fm%5Cx3dsb_he%2Cd%2Frt%5Cx3dj%2Fd%5Cx3d1%2Ft%5Cx3dzcms%2Frs%5Cx3dACT90oGWU4duK4Q5aR8xKQcV-eqzv5iDFw%27%29%3Bgoogle.xjs%3D1%3B%7Dgoogle.pmc%3D%7B"sb_he"%3A%7B"agen"%3Atrue%2C"cgen"%3Atrue%2C"client"%3A"heirloom-hp"%2C"dh"%3Atrue%2C"ds"%3A""%2C"exp"%3A"msedr"%2C"fl"%3Atrue%2C"host"%3A"google.com"%2C"jam"%3A0%2C"jsonp"%3Atrue%2C"msgs"%3A%7B"cibl"%3A"Clear%20Search"%2C"dym"%3A"Did%20you%20mean%3A"%2C"lcky"%3A"I%5Cu0026%2339%3Bm%20Feeling%20Lucky"%2C"lml"%3A"Learn%20more"%2C"oskt"%3A"Input%20tools"%2C"psrc"%3A"This%20search%20was%20removed%20from%20your%20%5Cu003Ca%20href%3D%5C"%2Fhistory%5C"%5Cu003EWeb%20History%5Cu003C%2Fa%5Cu003E"%2C"psrl"%3A"Remove"%2C"sbit"%3A"Search%20by%20image"%2C"srch"%3A"Google%20Search"%7D%2C"ovr"%3A%7B%7D%2C"pq"%3A""%2C"refoq"%3Atrue%2C"refpd"%3Atrue%2C"rfs"%3A%5B%5D%2C"scd"%3A10%2C"sce"%3A5%2C"stok"%3A"Kxe8ZMyjoP76IjKWk2dQvfoj-j0"%7D%2C"d"%3A%7B%7D%7D%3Bgoogle.y.first.push%28function%28%29%7Bif%28google.med%29%7Bgoogle.med%28%27init%27%29%3Bgoogle.initHistory%28%29%3Bgoogle.med%28%27history%27%29%3B%7D%7D%29%3Bif%28google.j%26%26google.j.en%26%26google.j.xi%29%7Bwindow.setTimeout%28google.j.xi%2C0%29%3B%7D%0A%3C%2Fscript%3E%3C%2Fdiv%3E%3C%2Fbody%3E%3C%2Fhtml%3E';
                i.src = '/sites/all/themes/prc_foundation/logo.png';
                //$('body').append(i);
                return !!i.width
            })();
            //imagesOn = (function () {
            //    var i = new Image();
            //    i.src = 'data:image/gif,GIF89a%01%00%01%00%80%00%00%00%00%00%FF%FF%FF!%F9%04%01%00%00%00%00%2C%00%00%00%00%01%00%01%00%00%02%01D%00%3B';
            //    return !!i.width
            //})();
            //$('input[name="faux_images"]').val(imagesOn);

            $('input[name="faux_monitor_color_depth"]').val(screen.colorDepth);
            $('input[name="faux_screen_resolution_width"]').val(screen.width);
            $('input[name="faux_screen_resolution_height"]').val(screen.height);

            function are_cookies_enabled() {
                var cookieEnabled = (navigator.cookieEnabled) ? true : false;

                if (typeof navigator.cookieEnabled == "undefined" && !cookieEnabled) {
                    document.cookie = "testcookie";
                    cookieEnabled = (document.cookie.indexOf("testcookie") != -1) ? true : false;
                }
                return (cookieEnabled);
            }
        }
    };
})(jQuery);
