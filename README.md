# ハード班ドローン作り  
***記録***  
*2020年*  
- **11/10(火)現在**  
>複数のプログラムを試みたがうまくいかず...  
試みたプログラムとその参照先のアドレスは`inception.ino`にのってます。  
誰かいつか検証して下さい... (さすピンはあってた)  
  
  ---
   
- **11/21(土)活動報告(報告者:田中裕)**  
>・４つのモーターにおいて単一のピンでのPWM制御に成功した。(tanaka\brushledd_solo_control.inoを使用)　  
  
 ---
  
- **11/23(月)活動報告(報告者:田中裕)**    

>・4つのモーターにプロペラをつけて、実機が暴れないように木材に括りつけてモーターを作動させた。 結果、括り付けた木材が若干床から離れる位の揚力が観測できた。  
  
---

- **11/24(火)活動報告(報告者:田中裕)**
  
>・4つのモーターを2つのPWM信号で2つづつ制御しようと、試みたところ、プロペラをつけていない状態での正常運転はPC電源及びリポバッテリーともに確認した。しかし、プロペラをつけて再度試みたところ、リポバッテリーの場合は正常に運転したが、PC電源を用いた際、途中でモーターが停止し、電源のファンの停止も確認した　　
(tanaka\brushledd_double_control.inoを使用)　
<img width="318" alt="11_24" src="https://user-images.githubusercontent.com/74751686/101986981-a8f08380-3cd4-11eb-84b7-61670dce2846.PNG">


---
 　　
- **11/25(水)活動報告(報告者:田中裕)**  
>　11/24(火)の実験と同手順の実験を鉛蓄電池によって行ったところ、初回は正常に動作し、プロペラの回転数制御も行えた。    
  
>11/24に作成したスパークキラーを作動させた所、モーターが回らず、原因究明をする必要がでてきた。ここで、まずは単一のモーターにて実験することを計画し、PC電源で行った結果回らなかった。(後に確認した所、モーターのプラグを抜き差しする際に数本arduinoのジャンパー線が抜けていたことがわかったので、それが原因だと思われる。)その後4つともにプラグをつけてPC電源、リポバッテリーで行ったがうまくいかず、鉛蓄電池で実験を行うことになった.  
　鉛蓄電池にワニ口クリップつき同線を用いてモーターの電力供給部分を短絡させた所、いままでにない激しいスパークとともに鉛蓄電池の金属端子部分の樹脂から白い煙が噴き出した。危険を感じ、鉛蓄電池からワニ口を外し、鉛蓄電池を食塩水を用いて、無極性化した。　その後、arduinoに正常にプログラムが書き込めていることを確認し、白煙噴出の原因のために、配線を調べたが極性もすべて正しく、arduinoのリード線が抜けていたこと以外に異常が見受けられなかった。その後、同じ配線でarduinoのみ繋ぎ直した所、リポバッテリーにおいて正常に動作することを確認できた(回転数制御もきちんと行えた。)。結局、鉛蓄電池がお釈迦になった理由はわからなかった。  
追記)以下に正常なarduinoの配線を添付する。
<img width="541" alt="arduino_brushless_malch" src="https://user-images.githubusercontent.com/74751686/100613579-21ac2300-3358-11eb-8616-34e921e7bf31.PNG">　  
(無極性化の際に参考にした動画:https://www.youtube.com/watch?v=78alVithOEg)
  
***
- **11/26(木)活動報告(報告者:田中裕)**  　　
>11/25に行った鉛蓄電池の無極性化の結果、水色の液体が発生した。鉛蓄電池の中に希硫酸が含まれることから、水色が硫酸銅を示していると判断し、イオン化傾向の低い鉄やアルミを投入することで、銅が分離できると考えた。そこで、鉄のワイヤーをコイル状にし、やすったもの（表面積を増やすため）を無極性化を行っているバケツの中に入れたところ、10分程度で水色の液体が少し、黒色に変わっており、うっすらと溶液内に茶色の層ができていることを確認した(銅が析出したと考えている)。その後、同バケツにアルミ箔をくしゃくしゃにしたものを入れ、放置すると、10分程度で、茶色の沈殿が目立つようになったとともに、バケツの中から水色の溶液が確認できないようになったため、ダイソーで購入した灯油をくみ上げる機器を用いて、別のバケツに黒色になった溶液を移した。     
*** 
- **11/30(月)活動報告(報告者:田中裕)**
>リポバッテリーの充電器が届き、従来使用していたスパークキラー(写真1)を噛まして動作確認を行ったところ、スパークが発生した。充電が満タンになったことで、電力が増し、従来のスパークキラーではスパークを抑えることができなくなったと考える。このことから、スパークキラーの調整が必要になった。 
  まず、3[Ω]の抵抗を5つ並列にして試した所、バッテリーの接点から火花が確認できた。  
  <img width="428" alt="spake1" src="https://user-images.githubusercontent.com/74751686/100611280-751c7200-3354-11eb-951f-ac2db722dd01.PNG">
  さらに、2つの直列の抵抗を並列に2本接続した所、スパークの音はなったが火花は出なかった。  
  <img width="439" alt="spake_2" src="https://user-images.githubusercontent.com/74751686/100611324-85cce800-3354-11eb-92ba-ed83dca8aaee.PNG">
　上記の状態のスパークキラーを用いることで、ゆっくり接点を短絡させることで、スパークが高確率で起こらないようになった。また、リポバッテリーの充電器を得たことで、安定して動作実験が行えるようになった。今後は、姿勢制御に力を入れていきたい。  
  
---

- **12/3(木)活動報告(報告者:田中裕)**  
  

>モーターの4つそれぞれを、４つのPWM信号を用いて制御することに成功した。
(tanaka\brushless_quad__control.inoを使用)　   
<img width="356" alt="brushless_quad_control" src="https://user-images.githubusercontent.com/74751686/101986969-98d8a400-3cd4-11eb-834f-7eb2194031d8.PNG">

  
>gy-251(六軸ジャイロセンサ)にて、arduinoのI2Cdevライブラリを用いたyaw,pitch,roll角の測定に成功した。  
>>[手順]  
(1)(https://github.com/jrowberg/i2cdevlib)  でi2cdevライブラリをダウンロードする。      
(2)ダウンロートファイルの中の「arduino」というディレクトリの「i2cdev」および「MPU6050」を自前のarduinoの「libraries」に保存。  
※もし、もともと「libraries」が存在しなかった場合、arduinoというフォルダに直で「libraries」というフォルダを作成すればいい。  
(3)この段階で実行中、または展開中のarduinoIDEがあればすべて閉じて、再びIDEを開く。  
(4)IDEのメニューから「ファイル」→「スケッチ例」→「MPU6050_DMP6」という手順でファイルを開く。  
(5)ソース上部に記述してあるとおりにGY-251とarduinoの配線を行う。  
<img width="490" alt="arduino_gyro" src="https://user-images.githubusercontent.com/74751686/101012991-f9663380-35a6-11eb-9461-9dffd99964df.PNG"> 
  
***
- **2/17(水)活動報告(報告者:田中裕)**
  >・PID制御をExcelで実験してみた  (tanaka\PID制御(操作量-(g-U),誤差量-a).xlsxを参照)  
    詳しくはpdfにまとめてているので(tanaka\z軸方向のドローンの位置制御(PID).pdf)を見てください。  
  
  >・Excelで目的値に収束した式、ゲインをUnityの物理エンジンで試した見たところドローンモデルが振動した。
  →今後は物理エンジンで目標値に収束しなかった原因を究明する。  
  ↓見ずらいと思いますが一応gifを載せておきます。(赤い平面が目標の高さ)
  　
  ![Videotogif (1)](https://user-images.githubusercontent.com/74751686/108189951-a8e98580-7154-11eb-961c-724d6ad18262.gif)

  
***
- **2/20(土)活動報告(報告者:田中裕)**
>・従来1秒ごとにモーターの回転数を変換していたものを0.005秒ごとに変更した。
→(tanaka\sampling_control.ino)参照  
>ジャイロセンサ(gy-251)を用いてピッチ角(-180°~180°)にモーターの信号(1000~2000)を対応させて回転数を変動させた。  
[手順]  
※i2cdevライブラリをすでにインストール済みの場合は(1)~(3)は省略してよい  
(1)(https://github.com/jrowberg/i2cdevlib)  でi2cdevライブラリをダウンロードする。      
(2)ダウンロートファイルの中の「arduino」というディレクトリの「i2cdev」および「MPU6050」を自前のarduinoの「libraries」に保存。  
※もし、もともと「libraries」が存在しなかった場合、arduinoというフォルダに直で「libraries」というフォルダを作成すればいい。  
(3)この段階で実行中、または展開中のarduinoIDEがあればすべて閉じて、再びIDEを開く。  
(4)(tanaka\R3.2.20gyro_moter_control.ino)をarduinoに書き込み、以下の配線を行う。  
<img width="366" alt="gyro_moter" src="https://user-images.githubusercontent.com/74751686/108591224-f3643f80-73aa-11eb-83bf-de1f95029055.png">
(5)モーターをバッテリーに接続すると音だけがなって動かない（音がなったのは初期化が完了した合図で実際のピッチ角をまだジャイロセンサから読み取っていないためモーター自体は動作しない)    
(6)その後ArduinoIDEの上部の[ツール]からシリアルモニタを開きしばらく待つと、英語で「何か文字を打て」と言われるので、テキトーに文字を打つ。すると、なにかのロードが始まり、ピッチ角が読みだされ、また、モーターが動き出す。
  
***
  ***今後の課題***  
>~~・4つのモーターの制御にはPCの定電圧電源を用いたので、その制御がリチウムポリマーバッテリーでもできるのかを検証する。~~  
→*リチウムポリマーバッテリーを使っても4つのモーターの動作確認ができた。*

 >~~リポバッテリーの充電器を購入する。~~  
 →*動作確認済み*   

>鉛蓄電池がぽしゃった理由の究明   
→*スパークが原因であると考えることができるため、早急にスパークキラーを開発した。*  
  
>・モーターを一つ使うときにモーターに流れる電流、および、モーターの回転数を測定し、それを基準として４つのモーターがそれぞれ適切な動作を行っているかを確認する。   
  
>傾きの変化を感知して、モーターが動くような制御をおこなう。



   


# 参照  
https://www.robotshop.com/community/blog/show/rc-speed-controller-esc-arduino-library  
みんなVS CodeでArduinoしよう  
https://qiita.com/narikei/items/847613a8f01a9e1527d7