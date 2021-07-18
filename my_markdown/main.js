let content = document.getElementById("origin");
let view = document.getElementById("view");
let flag = 0;  //判断编辑状态 1表示回车取消编辑 2表示编辑列表
let obj = document.createElement("p");
obj.innerHTML = "origin flag";
function mainfunc(event) {
    //  await test(event);
// let promise = new Promise(function(resolve, reject) {
//     resolve("done!");
//   });
//   promise.then(
//     result => alert(content.value[content.value.length - 1]), 
//   );
    if (flag == 0) {
        if (event.key == "Enter") {
            view.innerHTML += '<br>';
        }
        else view.innerHTML += event.key;
    }

    if (flag == 1) {
        if(event.key == 'Enter')
            flag = 0;
        else 
            view.lastChild.innerHTML += event.key;
        
    }

    if (flag == 2){
        if(event.key == 'Enter')
        {
            
            if(obj.innerHTML != '') {let p = document.createElement("li");
            obj.parentNode.appendChild(p);
            obj = p;}

            else {
                flag = 0;
                obj.remove();
            }
        }
        else 
            obj.innerHTML += event.key;
    }

    if (event.key == ' ') {
        if (content.value[content.value.length-1] == "#") {
            let num = judge1();
            if (num != -1) {
                view.innerHTML = view.innerHTML.slice(0,view.innerHTML.lastIndexOf('#') - num + 1);
                let p = document.createElement(`h${num}`);
                view.appendChild(p);
                obj = p;
                flag = 1;
            }
        }

        if (content.value[content.value.length-1] == "-") {
            if (content.value[content.value.length-2] == '\n' || content.value.length - 1 == 0) {
                view.innerHTML = view.innerHTML.slice(0,view.innerHTML.length - 2);
                let p = document.createElement("ul");
                let p1 = document.createElement("li");
                view.appendChild(p);
                p.appendChild(p1);
                obj = p1;
                flag = 2;
            }
        }
        if (content.value[content.value.length-1] == "." && content.value[content.value.length-2] == "1") {
            if (content.value[content.value.length-3] == '\n' || content.value.length - 2 == 0) {
                view.innerHTML = view.innerHTML.slice(0,view.innerHTML.length - 3);
                let p = document.createElement("ol");
                let p1 = document.createElement("li");
                view.appendChild(p);
                p.appendChild(p1);
                obj = p1;
                flag = 2;
            }
        }
    }

    if(event.key == 'Enter')
    {
         if (content.value[content.value.length-1] == "*") {
            let num = judge2();
            if(num != -1){
                view.innerHTML = view.innerHTML.slice(0,view.innerHTML.lastIndexOf('*') - num);
                view.innerHTML += "<hr>";
            }
         }
    }

    if (event.key == '*') {
        if (judge2() == -1) {
            num = 1;
            let str = view.innerHTML.slice(0,view.innerHTML.length - 1);
            if (view.innerHTML[view.innerHTML.length - 2] == '\\') {
                view.innerHTML = view.innerHTML.slice(0,-2) + view.innerHTML.slice(-1);
                return;
            }
            if(str.lastIndexOf('*') != -1  && str.lastIndexOf('*') != str.length - 1 )
                {
                    view.innerHTML = view.innerHTML.slice(0,str.lastIndexOf('*'));
                    str = str.slice(str.lastIndexOf('*') + 1);
                    if (str[str.indexOf(obj.tagName.toLowerCase())-1] == '<') {
                        let p = document.createElement("b");
                        p.innerHTML = obj.innerHTML;
                        view.appendChild(p);
                        obj = p; 
                    }
                    else {let p = document.createElement("i");
                    p.innerHTML = str;
                    view.appendChild(p);
                    obj = p;}
                }
            
        }
        // else {
        //     num = 2;
        //     let str = view.innerHTML.slice(0,view.innerHTML.length - 2);
        //     if(str.lastIndexOf('*') != -1 && str[str.lastIndexOf('*')-1] != '\\' && str[str.lastIndexOf('*')-1] == '*')
        //         {
        //             view.innerHTML = view.innerHTML.slice(0,str.lastIndexOf('*'));
        //             str = str.slice(str.lastIndexOf('*'));
        //             let p = document.createElement("b");
        //             p.innerHTML = str;
        //             view.appendChild(p);
        //         }
        // }
    }

    if (event.key == ')') {
        if(view.innerHTML.lastIndexOf('(') != -1&&view.innerHTML[view.innerHTML.lastIndexOf('(')-1] == ']')
        {
            let url = view.innerHTML.slice(view.innerHTML.lastIndexOf('(')+1,view.innerHTML.lastIndexOf(')'));
            let tag = view.innerHTML.slice(view.innerHTML.lastIndexOf('[')+1,view.innerHTML.lastIndexOf(']'));
            view.innerHTML = view.innerHTML.slice(0,view.innerHTML.lastIndexOf('['));
            let p = document.createElement('a');
            p.innerHTML = tag;
            p.href = url;
            view.appendChild(p);
            obj = p;
        }
    }

}


// function test(event) {
//     return new Promise((resolve) => {
//         setTimeout(alert(content.value),1000);
//     })
// }

function judge1(){ //判断#数量
    let n = content.value.length;
    let num = 0;
    // while(content.value[n - num - 1] != '\n' && num <= 5 && n - num -1 >= 0) num++;
    // if(num <= 5 && content.value[n - num - 1] == '\n') return num;
    // if(num <= 5 && n- num - 1 == 0) return num;
    // else return -1;
    while(content.value[n - num - 1] == '#' && num <= 5 && n - num - 1 >= 0) num++;
    if(num > 5 || content.value[n - num - 1] == '\\') return -1;
    /*if(n - num - 1 < 0)*/ return num;
    // if(content.value.lastIndexOf("<br>") + 3 == n - num - 1) return num;
}

function judge2() { //判断*数量
    let n = content.value.length;
    let num = 0;
    // while(content.value[n - num - 1] != '\n' && num <= 5 && n - num -1 >= 0) num++;
    // if(num <= 5 && content.value[n - num - 1] == '\n') return num;
    // if(num <= 5 && n- num - 1 == 0) return num;
    // else return -1;
    while(content.value[n - num - 1] == '*' && num <= 5 && n - num -1 >= 0) num++;
    if(num > 5 || num < 3 || content.value[n -
         num - 1] == '\\') return -1;
    /*if(n - num - 1 < 0)*/ return num;
}

function otherfunc(event) {
    if (event.key == "Backspace") {
        if(content.value.lastIndexOf("\n") == content.value.length - 1 && view.lastChild.innerHTML == obj.innerHTML) return ;
        if(view.lastChild.innerHTML == obj.innerHTML ){
            flag = 1;
            view.lastChild.innerHTML = view.lastChild.innerHTML.slice(0, -1);
            if (obj != view.lastChild) {
                obj.innerHTML = obj.innerHTML.slice(0,-1);
            }
        }

        else view.innerHTML = view.innerHTML.slice(0, -1);
    }
}