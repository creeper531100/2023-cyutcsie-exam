關於 C4996:

	在使用 Visual Studio 編譯器，可能會遇到以下錯誤訊息：
	
	C4996: 'scanf': This function or variable may be unsafe. 
	Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
	
	這是由於編譯器認為使用 scanf 函數有安全風險
	請在檔案開頭定義 #define _CRT_SECURE_NO_WARNINGS 用於忽略此警告。

關於開啟檔案:

	不要急著雙擊打開文件!!!
	有時候這樣會導致系統自動使用預設程式開啟文件，這可能會使你無法正常閱讀或編輯文件。

	你可以右鍵開啟 選擇「編輯（E）」來開啟。
	另外，如果你發現文件格式出現問題，可以將記事本的字體設置為「細明體」。

關於讀檔:

	當需要讀取檔案中的格式化C字元陣列時，建議使用 FILE* 搭配 fscanf。
		FILE* file = fopen("a.txt", "r+");
		fscanf(file, "%d", &res);

	如果需要讀取 C++ 的 string 時，請用ifstream
		#include <fstream>
		fstream ifs("123.txt", ios::in);
		ifs >> res; //類似cin 之用法
	
	如果當需要讀取包含換行符號的文字檔案時，可以利用 fread 函數來讀取
		fread(你的字串, 一次讀取幾個位元, 長度, 檔案)

	在印出 string 時，應該使用 cout 而非 printf。
	適合使用 printf 的情境，是當需要印出 char [] 字元陣列時。
	
一些技巧:

	fstream ifs("123.txt", ios::in); // A6969
	float number;
	char first;
	file >> first >> number; 
	
	fstream 可以智慧地提取不同型態的數據，比如第一個字符 'A'，下一個浮點數 6969 等等。
	這樣，我們就可以透過 fstream 來快速地從字串中提取想要的數據。
	使用 fstream 的好處是，我們可以將不同型態的數據放入同一個字串中
	然後使用 fstream 來進行提取，不需要額外地進行字串處理。這樣可以大大減少複雜度。
	這也是在我部分檔案中使用 fstream 原因