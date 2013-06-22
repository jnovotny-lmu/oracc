var p3ControlsHeight = 110;

function cbdPopup(url,windowName,height,width,screenX,screenY,focus) {
  var cbdPopupWindow = window.open(url,windowName,
 "dependent,height="+height+","
 +"width="+width+","
 +"screenX="+screenX+","
 +"screenY="+screenY+","
 +"resizable,scrollbars");
  if (focus) {
      cbdPopupWindow.focus();
  }
  cbdPopupWindow;
}

function distprof2(project,glos,gxis) {
    cbdPopup('/'+project+'/'+glos+'?xis='+gxis,'dpframe',600,700,0,0,1);
}

function getWinHeight() {
  var myHeight = 0;
  if (typeof(window.innerHeight) == 'number') {
    //Non-IE
    myHeight = window.innerHeight;
  } else if (document.documentElement
	     && (document.documentElement.clientWidth 
		 || document.documentElement.clientHeight)) {
    //IE 6+ in 'standards compliant mode'
    myHeight = document.documentElement.clientHeight;
  } else if( document.body && (document.body.clientWidth 
			       || document.body.clientHeight)) {
    //IE 4 compatible
    myHeight = document.body.clientHeight;
  }
  return myHeight;
}

function p3asearch() {
//    alert('p3asearch');
    var xformuri = '/'+document.getElementById('project').value+'/as.xml';
    var oasPopupWindow = oasPopupWindow = window.open(xformuri,'oasrch',
 "dependent,height="+400+","
 +"width="+600+","
 +"screenX="+'0'+","
 +"screenY="+'0'+","
 +"resizable,scrollbars,toolbar");
    oasPopupWindow.focus();
}

function p3action(act) {
    document.getElementById('p3do').value = act;
    document.getElementById('p3form').submit();
}

function p3help() {
    popup('http://oracc.museum.upenn.edu/doc/user/p2/index.html','oraccHelp',900,800,0,0);
}

function p3item(type,nth) {
    document.getElementById('item').value = nth;
    document.getElementById('itemtype').value = type;
    document.getElementById('p3form').submit();    
}

function p3zoom(z) {
    if (z === '0') {
	document.getElementById('zoom').value = z;
	document.getElementById('page').value = document.getElementById('uzpage').value;
	document.getElementById('p3form').submit();
    } else {
	document.getElementById('zoom').value = z;
	document.getElementById('uzpage').value = document.getElementById('page').value;
	document.getElementById('page').value = '1';
	document.getElementById('p3form').submit();
    }
}

function p3Letter(l) {
    document.getElementById('glet').value = l;
    document.getElementById('p3form').submit();    
}

function p3Article(l) {
    p3Letter(l);
}

function p3setHeight() {
    var wh = getWinHeight();
    var h = wh - p3ControlsHeight;
    document.getElementById('p3left').style.height = h+'px';
    document.getElementById('p3right').style.height = h+'px';
}

function p3PageControls() {
    var outlineState = document.getElementById('p3outl').value;
    var newSorttype = document.getElementById('sorttype').value;
    document.getElementById('p3itemnav').style.display= 'none';
    document.getElementById('p3pagenav').style.display= 'block';
    if (outlineState === 'default') {
	document.getElementById('p3OSspecial').style.display = 'none';
	var d = document.getElementById('p3OSdefault');
	d.style.display = 'inline';
	selectItemByValue(d, newSorttype);
    } else {
	if (outlineState === 'special') {
	    document.getElementById('p3OSdefault').style.display = 'none';
	    var d = document.getElementById('p3OSdefault');
	    d.style.display = 'inline';
	    selectItemByValue(d, newSorttype);
	} else {
	    document.getElementById('p3OSspecial').style.display = 'none';
	    document.getElementById('p3OSdefault').style.display = 'none';
	}
    }
}

function p3GlosControls() {
    document.getElementById('p3OSspecial').style.display = 'none';
    document.getElementById('p3OSdefault').style.display = 'none';
    document.getElementById('p3cetype').style.display = 'none';
    document.getElementById('p3srchtype').style.display = 'none';
    document.getElementById('p3CbdLang').style.display= 'inline';
    if (document.getElementById('glet').value.length > 0) {
	document.getElementById('p3itemnav').style.display= 'none';
	document.getElementById('p3pagenav').style.display= 'none';
    }
}

function p3ItemControls() {
    var newItemtype = document.getElementById('itemtype').value;
    document.getElementById('p3itemnav').style.display= 'block';
    document.getElementById('p3pagenav').style.display= 'none';
    document.getElementById('p3srchtype').style.display = 'inline';
    selectItemByValue(document.getElementById('p3itemtype'), newItemtype);
    if (document.getElementById('transcheck').value === '1') {
	document.getElementById('transonly').checked = 'checked';
    }
    if (newItemtype === 'off') {
	p3PageControls();
    }
}

function p3PageControls() {
    var outlineState = document.getElementById('p3outl').value;
    var newSorttype = document.getElementById('sorttype').value;
    document.getElementById('p3CbdLang').style.display= 'none';
    document.getElementById('p3itemnav').style.display= 'none';
    document.getElementById('p3pagenav').style.display= 'block';
    document.getElementById('p3srchtype').style.display = 'inline';
    if (outlineState === 'default') {
	document.getElementById('p3OSspecial').style.display = 'none';
	var d = document.getElementById('p3OSdefault');
	d.style.display = 'inline';
	selectItemByValue(d, newSorttype);
    } else {
	if (outlineState === 'special') {
	    document.getElementById('p3OSdefault').style.display = 'none';
	    var d = document.getElementById('p3OSdefault');
	    d.style.display = 'inline';
	    selectItemByValue(d, newSorttype);
	} else {
	    document.getElementById('p3OSspecial').style.display = 'none';
	    document.getElementById('p3OSdefault').style.display = 'none';
	}
    }
}

function p3SrchControls() {
    var newSrchtype = document.getElementById('srchtype').value;
    if (newSrchtype === 'cbd') {
	p3GlosControls();
    } else {
	selectItemByValue(document.getElementById('p3srchtype'), newSrchtype);
	var newCetype = document.getElementById('cetype').value;
	selectItemByValue(document.getElementById('p3cetype'), newCetype);
	var newSrchtype = document.getElementById('srchtype').value;
	selectItemByValue(document.getElementById('p3srchtype'), newSrchtype);
	document.getElementById('p3cetype').style.display = 'inline';
	document.getElementById('p3srchtype').style.display = 'inline';
    }
}

function p3NoOutline() {
    var rt = document.getElementById('p3right');
    rt.style.width = '100%';
    rt.style.left = '0px';
    rt = document.getElementById('p3navRight');
    rt.style.width = '100%';
    rt.style.left = '0px';
    document.getElementById('p3left').style.display = 'none';
}

function p3controls() {
    var mode = document.getElementById('p3mode').value;
    if (mode === 'zoom') {
	document.getElementById('p3zoom').style.display = 'inline';
    } else {
	document.getElementById('p3zoom').style.display= 'none';
    }

    var what = document.getElementById('p3what').value;
    if (what === 'page') {
	p3PageControls();
    } else {
	p3ItemControls();
    }

    var prod = document.getElementById('p3prod').value;
    if (prod === 'srch') {
	p3SrchControls();
    } else {
	// alert('glos.length='+document.getElementById('glos').value.length);
	if (document.getElementById('glos').value.length > 0) {
	    p3GlosControls();
	}
	document.getElementById('p3cetype').style.display = 'none';
    }

    var uimode = document.getElementById('uimode').value;
    if (uimode === 'mini') {
	document.getElementById('topButtons').style.display = 'none';
	document.getElementById('p3banner').style.display = 'none';
	document.getElementById('p3srch').style.display = 'none';
	p3ControlsHeight = 25;
	document.getElementById('p3controls').style.height = p3ControlsHeight+'px';
	p3NoOutline();
    }

    return 1;
}


function
popxff(project,eid) {
    cbdPopup('/cgi-bin/xff?xff='+eid+'&project='+project,
	'xffwin',600,400,700,0,1);
}

function selectGlossary(proj,obj) {
    var selectedGlossary = obj.options[obj.selectedIndex];
    var urlString = '/'+proj+'/'+selectedGlossary.value;
    window.location = urlString;
}

function selectItemByValue(elmnt, value) {
    for (var i=0; i < elmnt.options.length; i++) {
	if (elmnt.options[i].value == value) {
//	    alert('selecting p3itemtype='+elmnt.options[i].value);
            elmnt.selectedIndex = i;
	}
    }
}

function selectURI(obj) {
    var selectedURI = obj.options[obj.selectedIndex];
    window.location = selectedURI.value;
}

function
showNote(e,nid) {
  if (!e) var e = event;
  var posx = 0;
  var posy = 0;
  var safari = 0;
  var ua = navigator.userAgent.toLowerCase(); 
  if (ua.indexOf('safari')!=-1){
    safari = 1;
  }

  if (!e) e = event;
  if (e.clientX || e.clientY) {
    posx = e.clientX - window.pageXOffset;
    if (e.clientY > 0) {
      posy = e.clientY;
      }
  } else if (e.pageX || e.pageY) {
    posx = e.pageX;
    posy = e.pageY;
//    alert('pageX,pageY='+posx+','+posy);
  }

//  alert('posx='+posx+'; posy='+posy);

  // posx and posy contain the mouse position relative to the document
  // Do something with this information

    note=document.getElementById(nid);
    if (note.style.visibility != "visible") {
	note.style.left = posx+'px';
	note.style.top = posy+'px';
	note.style.visibility='visible';
	note.style.zIndex = 3;
  }
  return 1;
}
function
hideNote(e,nid) {
    if (!e)
	e = event;
    note=document.getElementById(nid);
    // makes note element invisible
    note.style.visibility='hidden';
    note.style.zIndex = 0;
//    alert('note='+note+'; vis='+note.style.visibility);
    return 1;
}