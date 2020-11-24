# ハード班ドローン作り  
***記録***  
*2020年*  
- **11/10(火)現在**  
複数のプログラムを試みたがうまくいかず...  
試みたプログラムとその参照先のアドレスは`inception.ino`にのってます。  
誰かいつか検証して下さい... (さすピンはあってた)  
  
   
- **11/21(土)活動報告(報告者:田中裕)**  
>・４つのモーターにおいて単一のピンでのPWM制御に成功した。(tanaka\brushledd_solo_control.inoを使用)　  
  
 
>・PID制御を学び、モーターの回転数をPID制御通りに制御する。  
  
- **11/23(月)活動報告(報告者:田中裕)**    

>・4つのモーターにプロペラをつけて、実機が暴れないように木材に括りつけてモーターを作動させた。 結果、括り付けた木材が若干床から離れる位の揚力が観測できた。  

- **11/24(火)活動報告(報告者:田中裕)**
  
>4つのモーターを2つのPWM信号で2つづつ制御しようと、試みたところ、プロペラをつけていない状態での正常運転はPC電源及びリポバッテリーともに確認した。しかし、プロペラをつけて再度試みたところ、リポバッテリーの場合は正常に運転したが、PC電源を用いた際、途中でモーターが停止し、電源のファンの停止も確認した　　
(tanaka\brushledd_double_control.inoを使用)　 　　
  
***今後の課題***  
  >~~・4つのモーターの制御にはPCの定電圧電源を用いたので、その制御がリチウムポリマーバッテリーでもできるのかを検証する。~~  
→*リチウムポリマーバッテリーを使っても4つのモーターの動作確認ができた。*
  
>・モーターを一つ使うときにモーターに流れる電流、および、モーターの回転数を測定し、それを基準として４つのモーターがそれぞれ適切な動作を行っているかを確認する。   
 
>・PID制御を学び、モーターの回転数をPID制御通りに制御する。  
  
>リポバッテリーの充電器を購入する。  

# 参照  
https://www.robotshop.com/community/blog/show/rc-speed-controller-esc-arduino-library  
みんなVS CodeでArduinoしよう  
https://qiita.com/narikei/items/847613a8f01a9e1527d7