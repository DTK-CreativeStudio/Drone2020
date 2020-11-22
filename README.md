# ハード班ドローン作り  
**記録**  
*2020年*  
- 11/10(火)現在  
複数のプログラムを試みたがうまくいかず...  
試みたプログラムとその参照先のアドレスは`inception.ino`にのってます。  
誰かいつか検証して下さい... (さすピンはあってた)  

- 11/21(土)活動報告(報告者:田中裕)  
[成果]  
・４つのモーターにおいて単一のピンでのPWM制御に成功した。(brushledd_solo_comtrol.inoを使用) 
[今後の課題]   
・今回の制御にはPCの定電圧電源を用いたので、その制御がリチウムポリマーバッテリーでもできるのかを検証する。  

・モーターを一つ使うときにモーターに流れる電流、および、モーターの回転数を測定し、それを基準として４つのモーターがそれぞれ適切な動作を行っているかを確認する。


# 参照  
https://www.robotshop.com/community/blog/show/rc-speed-controller-esc-arduino-library  
みんなVS CodeでArduinoしよう  
https://qiita.com/narikei/items/847613a8f01a9e1527d7