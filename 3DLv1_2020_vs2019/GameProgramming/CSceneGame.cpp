#include "CSceneGame.h"
//OpenGL
#include "glut.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CKey.h"
#include "CMatrix.h"
#include "CTransform.h"
#include "CBullet.h"
#include "CTaskManager.h"
//CEnemyクラスのインクルード
#include "CEnemy.h"
#include "CEnemy2.h"
//
#include "CCollisionManager.h"
//
#include "CBillBoard.h"
//
#include "CCamera.h"
//
#include "CUtil.h"

void CSceneGame::Init() {
	mText.LoadTexture("FontWhite.tga",1,64);

	mBackGroundMatrix.Translate(0.0f, 0.0f, -500.0f);

	//三角コライダの確認
//	mColliderTriangle.Set(NULL, NULL, CVector(-50.0f, 0.0f, -50.0f), CVector(-50.0f, 0.0f, 50.0f), CVector(50.0f, 0.0f, -50.0f));
//	mColliderTriangle2.Set(NULL, NULL, CVector(50.0f, 0.0f, -50.0f), CVector(-50.0f, 0.0f, 50.0f), CVector(50.0f, 0.0f, 50.0f));

	//C5モデルの読み込み
	mModelC5.Load("c5.obj", "c5.mtl");

	mEye = CVector(1.0f, 2.0f, 3.0f);
	//モデルファイルの入力
	mModel.Load("f14.obj", "f14.mtl");
	mBackGround.Load("sky.obj", "sky.mtl");
	mCube.Load("cube.obj", "cube.mtl");

	CMatrix matrix;
	matrix.Print();

	//

	mPlayer.mpModel = &mModel;
	mPlayer.mScale = CVector(0.1f, 0.1f, 0.1f);
	//
	mPlayer.mPosition = CVector(0.0f, 7.5f, -190.0f) * mBackGroundMatrix;
	//mPlayer.mPosition = CVector(0.0f, 0.0f, -503.0f);
	mPlayer.mRotation = CVector(0.0f, 0.0f, 0.0f);

	//敵機のインスタンス作成
	new CEnemy(&mCube, CVector(-35.0f, -10.0f, 50.0f)*mBackGroundMatrix, CVector(), CVector(5.1f, 100.1f,240.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f)*mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));

	new CEnemy(&mCube, CVector(35.0f, -10.0f, 50.0f) * mBackGroundMatrix, CVector(), CVector(5.1f, 100.1f, 240.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));

	new CEnemy(&mCube, CVector(1.0f, -1.0f, 50.1f) * mBackGroundMatrix, CVector(), CVector(32.1f, 1.1f, 240.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));



	new CEnemy(&mCube, CVector(-18.1f, 1.1f, -130.0f) * mBackGroundMatrix, CVector(), CVector(12.1f, 5.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));

	new CEnemy(&mCube, CVector(18.1f, 1.1f, -130.0f) * mBackGroundMatrix, CVector(), CVector(12.1f, 5.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));

	new CEnemy(&mCube, CVector(1.0f, 11.1f, -130.0f) * mBackGroundMatrix, CVector(), CVector(32.1f, 15.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));



	new CEnemy(&mCube, CVector(-18.1f, 1.1f, -80.0f) * mBackGroundMatrix, CVector(), CVector(34.1f, 5.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));

	new CEnemy(&mCube, CVector(-18.1f, 11.1f, -80.0f) * mBackGroundMatrix, CVector(), CVector(50.1f, 10.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));



	new CEnemy(&mCube, CVector(18.1f, 1.1f, -20.0f) * mBackGroundMatrix, CVector(), CVector(34.1f, 5.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));

	new CEnemy(&mCube, CVector(18.1f, 11.1f, -20.0f) * mBackGroundMatrix, CVector(), CVector(50.1f, 10.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));


	new CEnemy(&mCube, CVector(-18.1f, 1.1f, 30.0f) * mBackGroundMatrix, CVector(), CVector(12.1f, 5.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));

	new CEnemy(&mCube, CVector(18.1f, 1.1f, 30.0f) * mBackGroundMatrix, CVector(), CVector(12.1f, 5.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));

	new CEnemy(&mCube, CVector(1.0f, 11.1f, 30.0f) * mBackGroundMatrix, CVector(), CVector(32.1f, 15.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));


	new CEnemy(&mCube, CVector(1.1f, 1.1f, 90.0f) * mBackGroundMatrix, CVector(), CVector(20.1f, 5.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));

	new CEnemy(&mCube, CVector(1.0f, 11.1f, 90.0f) * mBackGroundMatrix, CVector(), CVector(32.1f, 15.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));
	

	new CEnemy(&mCube, CVector(-18.1f, 1.1f, 140.0f) * mBackGroundMatrix, CVector(), CVector(12.1f, 5.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));

	new CEnemy(&mCube, CVector(18.1f, 1.1f, 140.0f) * mBackGroundMatrix, CVector(), CVector(12.1f, 5.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));

	new CEnemy(&mCube, CVector(1.0f, 11.1f, 140.0f) * mBackGroundMatrix, CVector(), CVector(32.1f, 15.1f, 5.1f));
	new CEnemy(&mCube, CVector(30.0f, 0.0f, 130.0f) * mBackGroundMatrix, CVector(), CVector(1.1f, 10.1f, 1.1f));


	//new CEnemy(&mModelC5, CVector(0.0f, 10.0f, -600.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	//new CEnemy(&mModelC5, CVector(30.0f, 10.0f, -630.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));

//	new CEnemy2(CVector(-15.0f, 15.0f, -90.0f)*mBackGroundMatrix, CVector(), CVector(0.1f, 0.1f, 0.1f));
//	new CEnemy2(CVector(15.0f, 15.0f, -150.0f)*mBackGroundMatrix, CVector(), CVector(0.1f, 0.1f, 0.1f));

//	new CEnemy2(CVector(-5.0f, 1.0f, -10.0f)*mBackGroundMatrix, CVector(), CVector(0.1f, 0.1f, 0.1f));
//	new CEnemy2(CVector(5.0f, 1.0f, -10.0f)*mBackGroundMatrix, CVector(), CVector(0.1f, 0.1f, 0.1f));

	//ビルボードの生成
	new CBillBoard(CVector(-6.0f, 3.0f, -10.0f), 1.0f, 1.0f);
	//背景モデルから三角コライダを生成
	//親インスタンスと行列はなし
	//mColliderMesh.Set(NULL, NULL, &mBackGround);
	mColliderMesh.Set(NULL, &mBackGroundMatrix, &mBackGround);
}

void CSceneGame::Update() {

	CTaskManager::Get()->Update();
	//コリジョンマネージャの衝突処理
//削除	CCollisionManager::Get()->Collision();
	CTaskManager::Get()->TaskCollision();


	if (CKey::Push('L'))
	{
		mEye.mX += 0.1f;
	}
	if (CKey::Push('J'))
	{
		mEye.mX -= 0.1f;
	}
	if (CKey::Push('I'))
	{
		mEye.mZ -= 0.1f;
	}
	if (CKey::Push('K'))
	{
		mEye.mZ += 0.1f;
	}
	if (CKey::Push('O'))
	{
		mEye.mY += 0.1f;
	}
	if (CKey::Push('M'))
	{
		mEye.mY -= 0.1f;
	}

	//視点の設定
	//gluLookAt(視点X, 視点Y, 視点Z, 中心X, 中心Y, 中心Z, 上向X, 上向Y, 上向Z)
	//gluLookAt(mEye.mX, mEye.mY, mEye.mZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

//	mPlayer.Update();
	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	if (CKey::Push(VK_RIGHT))
	{
		Camera.mRotation.mY += 2.0f;
	}
	if (CKey::Push(VK_LEFT))
	{
		Camera.mRotation.mY -= 2.0f;
	}
	//	e = CVector(-2.0f, 10.0f, -30.0f) * mPlayer.mMatrix;
	e = CVector(-2.0f, 10.0f, -30.0f) * CMatrix().RotateY(Camera.mRotation.mY) * mPlayer.mMatrix;
	//注視点を求める
	c = mPlayer.mPosition;
	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotate;
	//カメラの設定
	//gluLookAt(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);
	//カメラクラスの設定
	Camera.Set(e, c, u);
	Camera.Render();
	//	mPlayer.Render();

	mBackGround.Render(mBackGroundMatrix);

//	mPlayer.bullet.Update();
//	mPlayer.bullet.Render();

	//タスクリストの削除
	CTaskManager::Get()->Delete();
	CTaskManager::Get()->Render();

#ifdef _DEBUG
	//コライダの描画
	CCollisionManager::Get()->Render();
#endif
	if (false)
	{
		//2Dの描画開始
		CUtil::Start2D(-400, 400, -300, 300);
		//描画色の設定（緑色の半透明）
		glColor4f(239.0f / 256.0f, 175.0f / 256.0f, 0.0f, 1.0f);

		//2000ミリ秒待機
		//Sleep(2000);

		//文字列の描画
		mText.DrawString("MISSION CLEAR", -200, 100, 16, 32);

		//2Dの描画終了
		CUtil::End2D();
	}

}

