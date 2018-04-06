<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

/*
Route::get('/', function () {
    return view('welcome');
});

*/

Route::resource('/', 'Index\IndexController');
Route::resource('/alpha-imoveis/como-funciona', 'Index\ComofuncionaController');
Route::resource('/alpha-imoveis/signup', 'Index\SignupController');
Route::resource('/alpha-imoveis/login', 'Index\LoginController');
Route::resource('/alpha-imoveis/signup/create', 'Index\SignupController');
Route::resource('/alpha-imoveis/suporte', 'Index\SuporteController');


Route::post('/alpha-imoveis/suporte/enviar', function(Illuminate\Http\Request $request){
    var_dump($request->all());
});


/*
Route::group(['namespace' => 'Index'], function() {  // adicione a pasta onde esta o controller
    Route::get('/', 'IndexController@Index');
    Route::get('/alpha-imoveis/como-funciona', 'ComofuncionaController@Comofunciona');
    Route::get('/alpha-imoveis/signup', 'SignupController@Signup');
    Route::get('/alpha-imoveis/login', 'LoginController@Login');
    Route::get('/alpha-imoveis/signup/create', 'SuporteController@Index');
    
});
*/