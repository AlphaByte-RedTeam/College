unit UnitTransformation;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TformTransformation }

  TformTransformation = class(TForm)
    btnRotate: TButton;
    btnLoad: TButton;
    btnSave: TButton;
    btnMove: TButton;
    btnScale: TButton;
    imgSrc: TImage;
    imgMod: TImage;
    txtNote: TLabel;
    txtImgMod: TLabel;
    txtImgOri: TLabel;
    txtYVal: TLabel;
    txtXVal: TLabel;
    editX: TEdit;
    editY: TEdit;
    openDialog: TOpenDialog;
    saveDialog: TSaveDialog;
    procedure btnLoadClick(Sender: TObject);
  private

  public

  end;

var
  formTransformation: TformTransformation;

implementation

{$R *.lfm}

{ TformTransformation }

procedure TformTransformation.btnLoadClick(Sender: TObject);
var
  x, y: integer;
begin
  if (openDialog.Execute) then
  begin
    imgSrc.Picture.LoadFromFile(openDialog.FileName);
    for y:=0 to imgSrc.Height-1 do
    begin
      for x:=0 to imgSrc.Widht-1 do
      begin
        bmpR[x,y] := getRValue(imgSrc.Canvas.Pixels[x,y]);
        bmpG[x,y] := getGValue(imgSrc.Canvas.Pixels[x,y]);
        bmpB[x,y] := getBValue(imgSrc.Canvas.Pixels[x,y]);
      end;
    end;
  end;
end;

end.

