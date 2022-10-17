import java.io.*;
import java.util.*;


class Solution {
    
    static int[] visited = new int[360001];
    static ArrayList<int[]> loggs = new ArrayList<>();
    
    public String solution(String pt, String at, String[] logs) {
        
        String[] tmp = pt.split(":");
        int t1 = Integer.parseInt(tmp[0]);
        int t2 = Integer.parseInt(tmp[1]);
        int t3 = Integer.parseInt(tmp[2]);
        
        int play_time = t1 * 3600 + t2 * 60 + t3;
        
        tmp = at.split(":");
        
        t1 = Integer.parseInt(tmp[0]);
        t2 = Integer.parseInt(tmp[1]);
        t3 = Integer.parseInt(tmp[2]);
        
        int ad_time = t1 * 3600 + t2 * 60 + t3;
        
      
        for(int i = 0; i < logs.length; i++){
            
            String str1 = logs[i].substring(0,8);
            String str2 = logs[i].substring(9,17);
            
            tmp = str1.split(":");
            t1 = Integer.parseInt(tmp[0]);
            t2 = Integer.parseInt(tmp[1]);
            t3 = Integer.parseInt(tmp[2]);
            
            int start = t1 * 3600 + t2 * 60 + t3;
            
            tmp = str2.split(":");
            t1 = Integer.parseInt(tmp[0]);
            t2 = Integer.parseInt(tmp[1]);
            t3 = Integer.parseInt(tmp[2]);
            
            int end = t1 * 3600 + t2 * 60 + t3;
            
            
            for(int j = start; j<end; j++) visited[j]++;
            
        }
        
        
        long sum = 0;
        
        for(int i = 0; i< ad_time; i++){
            sum += visited[i];
        }
        
        int ss = 0;
        int ee = ad_time - 1;
        
        long ans = sum;
        int start_ans = ss;
        
        while(ee <= play_time ){
            
            sum -= visited[ss];
            ss++;       
            ee++;
            if(ee > play_time){
                break;
            }
            sum += visited[ee];
            
            if(ans < sum){
                ans = sum;
                start_ans = ss;
            }
            
            
        }
        
       
        
        int ans_hour = start_ans / 3600;
        int ans_min = (start_ans % 3600) / 60;
        int ans_sec = (start_ans % 3600) % 60;
        
        String answer = "";
        if((Integer.toString(ans_hour)).length() == 1){
            answer = answer + "0" + Integer.toString(ans_hour) + ":";
        }else{
            answer = answer + Integer.toString(ans_hour) + ":";
        }
        
        if((Integer.toString(ans_min)).length() == 1){
            answer = answer + "0" + Integer.toString(ans_min) + ":";
        }else{
            answer = answer + Integer.toString(ans_min) + ":";
        }
        
        if((Integer.toString(ans_sec)).length() == 1){
            answer = answer + "0" + Integer.toString(ans_sec);
        }else{
            answer = answer + Integer.toString(ans_sec);
        }
        
        
        return answer;
    }
}