import React from "react";

var today = new Date();
var year = today.getFullYear();

function Footer(){
    return (<div>
        <footer><p>Copyright © {year}</p></footer></div>);
}

export default Footer;