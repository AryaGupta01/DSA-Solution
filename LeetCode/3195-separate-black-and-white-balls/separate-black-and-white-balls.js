/**
 * @param {string} s
 * @return {number}
 */
let sortString = (stringg) => {
    return stringg.split("").sort().join("");
};
var minimumSteps = function(s) {
    let swap =0;
    let blackballcount=0;
    for(let i=0; i<s.length;i++){
        if(s[i]==='0'){
            swap+=blackballcount;
        }else{
            blackballcount++;
        }
    }
    return swap;
    
};