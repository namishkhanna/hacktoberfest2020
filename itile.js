const axios= require('axios');


axios.get("https://api.github.com/search/issues?q=repo:ansible/ansible+label:bug+state:closed&page=1&per_page=5")
     .then(res=>{
         let title=res.data.items[4].title;
         let fullbody= res.data.items[4].body.replace(/(\r\n|\n|\r)/gm,"").replace(/`/g,"").replace(/#/g,"").replace(/\*/g,"").replace(/<!--/g,"").replace(/-->/g,"").replace(/\s+/g, ' ').replace(/SUMMARY/g,"");
         let fullbodysplitttedArray=fullbody.split("ISSUE TYPE");
         console.log("<<<<<summary>>>>",fullbodysplitttedArray[0])
         console.log("<<<<title>>>>",title)
     })

//let string1=" Fix ansible-test docker container detection.* Attach test containers to the correct network.* Do not assume localhost for accesing Docker.* Look for containers on current network.* Always map /var/run/docker.sock into containers.This fixes issues when using a remote Docker host.* Support container IP lookup from networks list.* Fix container network attachment.* Remove redundant container detection messages.* Limit DOCKER_HOST parsing to TCP.* Restore docker socket existence check.The check is skipped if the docker hostname is not localhost."
// let string1=" habbfshffuirf wyegfwkjdfnqelqgr gquierhgnamfnvseiurhg  hfeiufhakjsd"
// console.log(string1.length)
// let string12=string1.substring(0,400);
// console.log(string12.length)