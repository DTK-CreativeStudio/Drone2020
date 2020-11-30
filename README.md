# ハード班ドローン作り  
***記録***  
*2020年*  
- **11/10(火)現在**  
>複数のプログラムを試みたがうまくいかず...  
試みたプログラムとその参照先のアドレスは`inception.ino`にのってます。  
誰かいつか検証して下さい... (さすピンはあってた)  
  
   
- **11/21(土)活動報告(報告者:田中裕)**  
>・４つのモーターにおいて単一のピンでのPWM制御に成功した。(tanaka\brushledd_solo_control.inoを使用)　  
  
 
  
- **11/23(月)活動報告(報告者:田中裕)**    

>・4つのモーターにプロペラをつけて、実機が暴れないように木材に括りつけてモーターを作動させた。 結果、括り付けた木材が若干床から離れる位の揚力が観測できた。  

- **11/24(火)活動報告(報告者:田中裕)**
  
>・4つのモーターを2つのPWM信号で2つづつ制御しようと、試みたところ、プロペラをつけていない状態での正常運転はPC電源及びリポバッテリーともに確認した。しかし、プロペラをつけて再度試みたところ、リポバッテリーの場合は正常に運転したが、PC電源を用いた際、途中でモーターが停止し、電源のファンの停止も確認した　　
(tanaka\brushledd_double_control.inoを使用)　 　　
- **11/25(水)活動報告(報告者:田中裕)**  
>　11/24(火)の実験と同手順の実験を鉛蓄電池によって行ったところ、初回は正常に動作し、プロペラの回転数制御も行えた。    
  
>11/24に作成したスパークキラーを作動させた所、モーターが回らず、原因究明をする必要がでてきた。ここで、まずは単一のモーターにて実験することを計画し、PC電源で行った結果回らなかった。(後に確認した所、モーターのプラグを抜き差しする際に数本arduinoのジャンパー線が抜けていたことがわかったので、それが原因だと思われる。)その後4つともにプラグをつけてPC電源、リポバッテリーで行ったがうまくいかず、鉛蓄電池で実験を行うことになった.  
　鉛蓄電池にワニ口クリップつき同線を用いてモーターの電力供給部分を短絡させた所、いままでにない激しいスパークとともに鉛蓄電池の金属端子部分の樹脂から白い煙が噴き出した。危険を感じ、鉛蓄電池からワニ口を外し、鉛蓄電池を食塩水を用いて、無極性化した。　その後、arduinoに正常にプログラムが書き込めていることを確認し、白煙噴出の原因のために、配線を調べたが極性もすべて正しく、arduinoのリード線が抜けていたこと以外に異常が見受けられなかった。その後、同じ配線でarduinoのみ繋ぎ直した所、リポバッテリーにおいて正常に動作することを確認できた(回転数制御もきちんと行えた。)。結局、鉛蓄電池がお釈迦になった理由はわからなかった。　  
(無極性化の際に参考にした動画:https://www.youtube.com/watch?v=78alVithOEg)

- **11/26(木)活動報告(報告者:田中裕)**  　　
>11/25に行った鉛蓄電池の無極性化の結果、水色の液体が発生した。鉛蓄電池の中に希硫酸が含まれることから、水色が硫酸銅を示していると判断し、イオン化傾向の低い鉄やアルミを投入することで、銅が分離できると考えた。そこで、鉄のワイヤーをコイル状にし、やすったもの（表面積を増やすため）を無極性化を行っているバケツの中に入れたところ、10分程度で水色の液体が少し、黒色に変わっており、うっすらと溶液内に茶色の層ができていることを確認した(銅が析出したと考えている)。その後、同バケツにアルミ箔をくしゃくしゃにしたものを入れ、放置すると、10分程度で、茶色の沈殿が目立つようになったとともに、バケツの中から水色の溶液が確認できないようになったため、ダイソーで購入した灯油をくみ上げる機器を用いて、別のバケツに黒色になった溶液を移した。    
- **11/30(月)活動報告(報告者:田中裕)**
>リポバッテリーの充電器が届き、従来使用していたスパークキラー(写真1)を噛まして動作確認を行ったところ、スパークが発生した。充電が満タンになったことで、電力が増し、従来のスパークキラーではスパークを抑えることができなくなったと考える。このことから、スパークキラーの調整が必要になった。 
  まず、3[Ω]の抵抗を5つ並列にして試した所、バッテリーの接点から火花が確認できた。さらに、2つの直列の抵抗を並列に2本接続した所、スパークの音はなったが火花は出なかった。  
  |***![aaa](https://github.com/DTK-CreativeStudio/Drone2020/tree/master/cirkit/sake.PNG)***|

  |![](https://github.com/DTK-CreativeStudio/Drone2020/tree/master/cirkit/sake.PNG)|
  
  ***今後の課題***  
  >~~・4つのモーターの制御にはPCの定電圧電源を用いたので、その制御がリチウムポリマーバッテリーでもできるのかを検証する。~~  
→*リチウムポリマーバッテリーを使っても4つのモーターの動作確認ができた。*
  
 >~~リポバッテリーの充電器を購入する。~~  
 →*すでに到着済み*   

>鉛蓄電池がぽしゃった理由の究明 
→
  >・モーターを一つ使うときにモーターに流れる電流、および、モーターの回転数を測定し、それを基準として４つのモーターがそれぞれ適切な動作を行っているかを確認する。   
 
>・PID制御を学び、モーターの回転数をPID制御通りに制御する。


   


# 参照  
https://www.robotshop.com/community/blog/show/rc-speed-controller-esc-arduino-library  
みんなVS CodeでArduinoしよう  
https://qiita.com/narikei/items/847613a8f01a9e1527d7