# XinuOS

## 環境作成

### 準備物

* BBB
* USBシリアルケーブル
* microSDカード



### 前提

* wsl 18.04

### 本体のバイナリビルドの手順

* armのクロスコンパイラ環境をインストールする
    * 『[ARMのGCCコンパイル環境を構築する](https://www.yokoweb.net/2018/03/07/wsl-ubuntu-arm-gcc/)』を実施する
    * プロジェクトにもcross-compilerがついているが、実行形式が32bit版のため実行できない
* 本体プロジェクトをダウンロードする
    * <方法1>安定版:本家のリンク[An ARM version (BeagleBone Black board from TI)](https://www.cs.purdue.edu/homes/comer/downloads/Xinu_Book_And_Code/BeagleBoneBlack/Xinu-BeagleBoneBlack.tar.gz)からダウンロードする
    * <方法2>最新版:github版[real-xinu/xinu-bbb](https://github.com/real-xinu/xinu-bbb)からダウンロードする
* Makefileを修正する
    * コンパイラの修正(同梱の実行できないものではなく、インストールしたものを指定するように変更する)
```
  #########################################################################
  #									#
  #									#
  #  Makefile for Beaglebone Black version of the Xinu operating system	#
  #									#
  #  includes: .deps and .defs						#
  #									#
  #									#
  #########################################################################
  
- COMPILER_ROOT	=	../cross_compiler/bin/arm-none-eabi-
+ COMPILER_ROOT	=	arm-none-eabi-
  PNAME		=	bbb
  PLAT		=	Platform_$(PNAME)
  TOPDIR		=	..
```
* mkimageの再配置
    * `uboot-tool`配下の`mkimage`もarch違いにより実行できないため、削除し、前段階で環境作成時に生成されている`mkimage`をコピーして配置する
* ビルド
    * `compile`フォルダで`make`を実行し、『`xinu`』が生成されれば成功



### 参考手順書

* [XinuBBB](https://github.com/jarrocha/XinuBBB)
* [Getting started with Embedded Xinu](https://github.com/xinu-os/xinu/blob/master/docs/Getting-Started.rst)

### (kernelをコンパイルするための)クロスコンパイラの設定

* [ARMのGCCコンパイル環境を構築する](https://www.yokoweb.net/2018/03/07/wsl-ubuntu-arm-gcc/)