string encode(string src)
{     
    int len = 0;
    string res;
    char prev = src[0];
    
    for(char c : src){
        if(c == prev){
            len++;
        }else{
            res.push_back(prev);
            res.append(to_string(len));
            
            len = 1;
            prev = c;
        }
    }
    
    res.push_back(prev);
    res.append(to_string(len));
    
    
    return res;
}     